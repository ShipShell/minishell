/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:22:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 17:11:21 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_used_double_pointer(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_used_str_list(t_list *tmp_token)
{
	t_list	*removing_nodes;

	while (tmp_token)
	{
		free(tmp_token->content);
		removing_nodes = tmp_token;
		tmp_token = tmp_token->next;
		free(removing_nodes);
	}
}

void	free_redir_list(t_list *redir)
{
	t_list	*removing_nodes;

	while (redir)
	{
		free(((t_redir *)redir->content)->filename);
		removing_nodes = redir;
		redir = redir->next;
		free(removing_nodes);
	}
}

void	free_tokenized_single_cmd_list(t_list *cmd_list)
{
	t_list	*removing_nodes;

	while (cmd_list)
	{
		free_used_double_pointer(((t_cmd *)cmd_list->content)->token);
		free_redir_list(((t_cmd *)cmd_list->content)->redir);
		if (((t_cmd *)cmd_list->content)->re_in != NULL)
			free(((t_cmd *)cmd_list->content)->re_in);
		if (((t_cmd *)cmd_list->content)->re_out != NULL)
			free(((t_cmd *)cmd_list->content)->re_out);
		removing_nodes = cmd_list;
		free(cmd_list->content);
		cmd_list = cmd_list->next;
		free(removing_nodes);
	}
}
