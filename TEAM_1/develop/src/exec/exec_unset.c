/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:42:23 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 13:44:33 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_env(char *key)
{
	t_env *env;
	t_env *bef;
	t_env *next;

	env = g_env;
	bef = 0;
	while (env)
	{
		next = env->next;
		if (ft_strcmp(env->key, key) == 0)
		{
			if (bef)
				bef->next = next;
			else
				g_env = next;
			free(env->key);
			if (env->val)
				free(env->val);
			free(env);
			break ;
		}
		bef = env;
		env = env->next;
	}
}

int		exec_unset(t_cmd *cmd)
{
	t_env	*env;
	int		i;

	env = g_env;
	i = 1;
	while (cmd->command[i])
	{
		remove_env(cmd->command[i]);
		i++;
	}
	return (0);
}
