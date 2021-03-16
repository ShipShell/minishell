/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:41:50 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 13:57:23 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_val(t_cmd *cmd, int i, int cnt)
{
	while (cmd->command[i])
	{
		ft_putstr(cmd->command[i]);
		if (i < cnt - 1)
			ft_putstr(" ");
		i++;
	}
}

int		exec_echo(t_cmd *cmd)
{
	t_env	*env;
	int		cnt_arg;

	env = g_env;
	cnt_arg = chk_arg_cnt(cmd);
	if (cnt_arg > 2 && ft_strcmp(cmd->command[1], "-n") == 0)
		print_val(cmd, 2, cnt_arg);
	else
	{
		print_val(cmd, 1, cnt_arg);
		write(1, "\n", 1);
	}
	return (0);
}
