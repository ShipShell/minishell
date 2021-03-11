/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:41:23 by hson              #+#    #+#             */
/*   Updated: 2021/03/11 14:03:18 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		chk_arg_cnt(t_cmd *cmd)
{
	int i;

	i = 0;
	if (cmd->command)
	{
		while (cmd->command[i])
			i++;
		return (i);
	}
	return (0);
}

int		chk_arg_digit(char *val)
{
	int i;

	i = 0;
	if (val)
	{
		while (val[i])
		{
			if (!ft_isdigit(val[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int		exec_exit(t_cmd *cmd)
{
	int cnt_arg;
	int	isdigit;

	cnt_arg = chk_arg_cnt(cmd);
	isdigit = chk_arg_digit(cmd->command[1]);
	if (cmd->command[1])
	{
		if (isdigit == 0)
		{
			ft_putstr("exit\n");
			exit(num_arg_error(cmd, 255));
		}
		if (cnt_arg > 2)
		{
			ft_putstr("exit\n");
			return (too_many_arg_error(cmd, 1));
		}
		ft_putstr("exit\n");
		exit(ft_atoi(cmd->command[1]));
	}
	ft_putstr("exit\n");
	exit(0);
	return (EXIT_SUCCESS);
}
