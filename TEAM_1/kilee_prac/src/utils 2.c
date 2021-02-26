/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:30:00 by kilee             #+#    #+#             */
/*   Updated: 2021/02/26 14:57:33 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_cmd		*new_cmd(char **new_cmd)
{
	t_cmd	*new;

	if (!(new = (t_cmd *)malloc(sizeof(t_cmd) * 1)))
		return (NULL);
	new->command = new_cmd;
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
