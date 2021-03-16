/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:38:37 by hson              #+#    #+#             */
/*   Updated: 2021/03/12 10:57:43 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		num_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd->command[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	return (err_num);
}

int		too_many_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(": too many arguments\n", 2);
	return (err_num);
}

int		open_error(char *file)
{
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (-1);
}

int		no_home_error(t_cmd *cmd, int err_num)
{
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(": HOME not set\n", 2);
	return (err_num);
}
