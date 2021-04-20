/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 18:36:47 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	put_not_number_err(t_cmd *cmd)
{
	ft_putstr_fd("exit\nshipshell: exit: ", 1);
	ft_putstr_fd(cmd->token[1], 1);
	ft_putstr_fd(": numeric argument required\n", 1);
	exit(255);
	return (-1);
}

int	put_too_many_err(void)
{
	ft_putstr_fd("exit\nshipshell: exit: ", 1);
	ft_putstr_fd("too many arguments\n", 1);
	g_exit_code = 1;
	return (-1);
}

int	ft_exit(t_cmd *cmd)
{
	if (!cmd->token[1])
		exit(g_exit_code);
	else if (cmd->token[1][0] < '0' || cmd->token[1][0] > '9')
		return (put_not_number_err(cmd));
	else if (cmd->token[2])
		return (put_too_many_err());
	else if (cmd->token[1] && cmd->token[2] == 0)
	{
		g_exit_code = atoi(cmd->token[1]);
		exit(g_exit_code);
	}
	return (1);
}
