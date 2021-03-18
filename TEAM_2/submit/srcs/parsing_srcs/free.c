/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:22:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 15:53:58 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_used_double_pointer(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
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
		((t_redir *)redir->content)->filename = NULL;
		free((t_redir *)redir->content);
		redir->content = NULL;
		removing_nodes = redir;
		redir = redir->next;
		free(removing_nodes);
		removing_nodes = NULL;
	}
}

void	free_tokenized_single_cmd_list(t_list *cmd_list)
{
	t_list	*removing_nodes;

	while (cmd_list)
	{
		free_used_double_pointer(((t_cmd *)cmd_list->content)->token);
		free_redir_list(((t_cmd *)cmd_list->content)->redir);
		removing_nodes = cmd_list;
		free(cmd_list->content);
		cmd_list = cmd_list->next;
		free(removing_nodes);
	}
}
