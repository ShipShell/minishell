/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:30:00 by kilee             #+#    #+#             */
/*   Updated: 2021/03/03 17:12:41 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_cmd		*new_cmd(char *cmd_str)
{
	t_cmd	*new;

	if (!(new = (t_cmd *)malloc(sizeof(t_cmd) * 1)))
		return (NULL);
	new->cmd_str = cmd_str;
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

void	delete_data_in_cmd(void *data)
{
	t_cmd	*cmd;
	int		i;

	cmd = (t_cmd *)data;
	i = 0;
	free(cmd->cmd_str);
	if (cmd->command != NULL)
	{
		while (cmd->command[i])
			++i;
		ft_free_arr(cmd->command, i);
	}
}

void	delete_one_cmd(t_cmd *cmd, void (*del)(void*))
{
	if (cmd == NULL)
		return ;
	if (del)
		del(cmd);
	free(cmd);
}

void	delete_cmd_list(t_cmd **lst, void (*del)(void*))
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

t_env		*new_env(char **key_value)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env) * 1)))
		return (NULL);
	new->key = ft_strdup(key_value[0]);
	new->value = ft_strdup(key_value[1]);
	new->next = NULL;
	return (new);
}

void		add_back_new_env(t_env **envs, t_env *new_env)
{
	t_env	*cur;

	if (*envs == NULL)
	{
		*envs = new_env;
		return ;
	}
	cur = *envs;
	while (cur->next)
		cur = cur->next;
	cur->next = new_env;
}
