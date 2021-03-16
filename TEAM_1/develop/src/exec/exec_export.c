/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:41:12 by hson              #+#    #+#             */
/*   Updated: 2021/03/16 13:02:06 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(void)
{
	t_env	*env;
	t_env	**sort_env;
	int		size;
	int		i;

	env = g_env;
	size = chk_arg_cnt_env();
	sort_env = (t_env **)malloc(sizeof(t_env *) * (size + 1));
	i = -1;
	while (++i < size)
	{
		sort_env[i] = env;
		env = env->next;
	}
	sort_env[i] = 0;
	ft_sort_env(sort_env, size);
	print_export_sub(sort_env);
	free(sort_env);
}

void	put_env(char *str)
{
	char	*key;
	char	*val;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	key = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(key, str, i + 1);
	j = 0;
	if (str[i])
	{
		while (j++ < i + 1)
			str++;
		val = str;
	}
	else
		val = 0;
	lst_change_add_env(key, val);
	free(key);
}

int		exec_export(t_cmd *cmd)
{
	t_env	*env;
	int		i;

	env = g_env;
	i = 1;
	if (!cmd->command[1])
		print_export();
	while (cmd->command[i])
	{
		if (ft_isdigit(cmd->command[i][0]) || cmd->command[i][0] == '=')
			return (not_valid_idt(cmd, cmd->command[i], 1));
		put_env(cmd->command[i]);
		i++;
	}
	return (0);
}
