/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:53 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 15:52:38 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	del_env(t_list *before, t_list *env_list)
{
	if (before == 0)
	{
		g_env = env_list;
		free(((t_env *)env_list->content)->key);
		free(((t_env *)env_list->content)->value);
		free(env_list->content);
		g_env = env_list->next;
		free(env_list);
	}
	else
	{
		before->next = env_list->next;
		free(((t_env *)env_list->content)->key);
		free(((t_env *)env_list->content)->value);
		free(env_list->content);
		free(env_list);
	}
	return (0);
}

int	find_env(t_cmd *cmd)
{
	t_list	*env_list;
	t_list	*before;
	int		i;

	i = 0;
	while (cmd->token[++i])
	{
		before = 0;
		env_list = g_env;
		while (env_list)
		{
			if (!ft_strcmp(((t_env *)env_list->content)->key, cmd->token[i]))
			{
				del_env(before, env_list);
				break ;
			}
			before = env_list;
			env_list = env_list->next;
		}
	}
	return (0);
}

int	ft_unset(t_cmd *cmd)
{
	find_env(cmd);
	return (1);
}
