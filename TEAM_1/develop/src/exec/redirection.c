/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:41:31 by hson              #+#    #+#             */
/*   Updated: 2021/03/11 11:28:28 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		do_redir_in(t_redir *in)
{
	int		fd;
	t_list	*tmp;

	tmp = in->file;
	while (tmp->next)
	{
		if ((fd = open(tmp->content, O_RDONLY)) == -1)
			return (open_error(tmp->content));
		if (close(fd) == -1)
			ft_error();
		tmp = tmp->next;
	}
	if ((in->fd = open(tmp->content, O_RDONLY)) == -1)
		return (open_error(tmp->content));
	in->tmp_std = dup(0);
	dup2(in->fd, 0);
	return (0);
}

int		do_redir_out(t_redir *out)
{
	int		fd;
	t_list	*tmp;

	tmp = out->file;
	while (tmp->next)
	{
		fd = open(tmp->content, O_WRONLY | O_TRUNC | O_CREAT, 0666);
		if (close(fd) == -1)
			ft_error();
		tmp = tmp->next;
	}
	if (out->is_double == 1)
		out->fd = open(tmp->content, O_WRONLY | O_APPEND | O_CREAT, 0666);
	else
		out->fd = open(tmp->content, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	out->tmp_std = dup(1);
	dup2(out->fd, 1);
	return (0);
}

int		change_redir(t_cmd *cmd)
{
	if (cmd->redir_in && (do_redir_in(cmd->redir_in) == -1))
		return (-1);
	if (cmd->redir_out)
		do_redir_out(cmd->redir_out);
	return (0);
}

void	getback_redir(t_cmd *cmd)
{
	if (cmd->redir_in)
	{
		dup2(cmd->redir_in->tmp_std, 0);
		close(cmd->redir_in->tmp_std);
	}
	if (cmd->redir_out)
	{
		dup2(cmd->redir_out->tmp_std, 1);
		close(cmd->redir_out->tmp_std);
	}
}
