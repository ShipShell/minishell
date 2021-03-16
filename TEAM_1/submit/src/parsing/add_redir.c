/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:48:34 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 12:53:39 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_redir(t_cmd *cmd, int i, int in_count, int out_count)
{
	if (out_count == 1)
		add_out_redir(cmd, i, FALSE);
	else if (out_count == 2)
		add_out_redir(cmd, i, TRUE);
	else if (in_count == 1)
		add_in_redir(cmd, i, FALSE);
	else if (in_count == 2)
		add_in_redir(cmd, i, TRUE);
	else if (cmd->isredir == TRUE)
		pull_token(cmd, i);
}

void	add_out_redir(t_cmd *cmd, int i, t_bool isdouble)
{
	t_list	*new;

	cmd->isredir = TRUE;
	if (cmd->redir_out == NULL)
		cmd->redir_out = init_redir();
	new = ft_lstnew(ft_strdup(cmd->command[i]));
	ft_lstadd_back(&cmd->redir_out->file, new);
	cmd->redir_out->is_double = isdouble;
	free(cmd->command[i]);
	cmd->command[i] = NULL;
}

void	add_in_redir(t_cmd *cmd, int i, t_bool isdouble)
{
	t_list	*new;

	cmd->isredir = TRUE;
	if (cmd->redir_in == NULL)
		cmd->redir_in = init_redir();
	new = ft_lstnew(ft_strdup(cmd->command[i]));
	ft_lstadd_back(&cmd->redir_in->file, new);
	cmd->redir_in->is_double = isdouble;
	free(cmd->command[i]);
	cmd->command[i] = NULL;
}

void	pull_token(t_cmd *cmd, int i)
{
	int		last;

	last = 0;
	while (cmd->command[last])
		++last;
	cmd->command[last] = cmd->command[i];
	cmd->command[i] = NULL;
}
