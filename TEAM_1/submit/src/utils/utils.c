/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:30:00 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 13:04:58 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_cmd		*new_cmd(char *cmd_str)
{
	t_cmd	*new;

	if (!(new = (t_cmd *)malloc(sizeof(t_cmd) * 1)))
		return (NULL);
	new->redir_in = NULL;
	new->redir_out = NULL;
	new->cmd_str = cmd_str;
	new->ispipe = FALSE;
	new->ispath = FALSE;
	new->isredir = FALSE;
	new->command = NULL;
	new->next = NULL;
	return (new);
}

void		add_back_new_cmd(t_cmd **cmds, t_cmd *new_cmd)
{
	t_cmd	*cur;

	if (*cmds == NULL)
	{
		*cmds = new_cmd;
		return ;
	}
	cur = *cmds;
	while (cur->next)
		cur = cur->next;
	cur->next = new_cmd;
}

void		delete_data_in_cmd(void *data)
{
	t_cmd	*cmd;
	int		i;

	cmd = (t_cmd *)data;
	i = 0;
	free(cmd->cmd_str);
	delete_redir_in_cmd(cmd->redir_in);
	delete_redir_in_cmd(cmd->redir_out);
	if (cmd->command != NULL)
	{
		while (cmd->command[i])
			++i;
		ft_free_arr(cmd->command, i);
	}
}

void		delete_cmd_list(t_cmd **lst, void (*del)(void*))
{
	t_cmd	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		delete_one_cmd(*lst, del);
		(*lst) = temp;
	}
}

void		delete_one_cmd(t_cmd *cmd, void (*del)(void*))
{
	if (cmd == NULL)
		return ;
	if (del)
		del(cmd);
	free(cmd);
	cmd = NULL;
}
