/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:41:09 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 15:14:00 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		chk_arg_cnt_env(void)
{
	t_env	*env;
	int		i;

	env = g_env;
	i = 0;
	while (env)
	{
		if (env->key)
			i++;
		env = env->next;
	}
	return (i);
}

void	ft_sort_env(t_env **sort_env, int size)
{
	int		i;
	int		j;
	t_env	*tmp;

	i = 0;
	j = 0;
	while (j++ < size)
	{
		i = 0;
		while (++i < size)
		{
			if (ft_strcmp(sort_env[i - 1]->key, sort_env[i]->key) > 0)
			{
				tmp = sort_env[i - 1];
				sort_env[i - 1] = sort_env[i];
				sort_env[i] = tmp;
			}
		}
	}
}

void	print_export_sub(t_env **sort_env)
{
	int	i;
	int	j;

	i = 0;
	while (sort_env[i])
	{
		ft_putstr(sort_env[i]->key);
		if (sort_env[i]->val)
		{
			write(1, "=\"", 2);
			j = 0;
			while (sort_env[i]->val[j])
			{
				if (sort_env[i]->val[j] == '\"')
					write(1, "\\", 1);
				ft_putchar(sort_env[i]->val[j++]);
			}
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}
