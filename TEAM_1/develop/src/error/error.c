/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:38:07 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 13:38:14 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		num_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": ");
	ft_putstr(cmd->command[1]);
	ft_putstr(": numeric argument required\n");
	return (err_num);
}

int		too_many_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": too many arguments\n");
	return (err_num);
}

int		no_command_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": command not found\n");
	return (err_num);
}

int		no_file_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	if (cmd->command[1])
	{
		ft_putstr(": ");
		ft_putstr(cmd->command[1]);
	}
	ft_putstr(": No such file or directory\n");
	return (err_num);
}

int		not_valid_idt(t_cmd *cmd, char *arg, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": '");
	ft_putstr(arg);
	ft_putstr("': not a valid identifierd\n");
	return (err_num);
}
