/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:41:53 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 13:46:59 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_env(t_cmd *cmd)
{
	t_env	*env;

	env = g_env;
	(void)cmd;
	while (env)
	{
		if (env->val)
		{
			ft_putstr(env->key);
			write(1, "=", 1);
			ft_putstr(env->val);
			write(1, "\n", 1);
		}
		env = env->next;
	}
	return (0);
}
