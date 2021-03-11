/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:38:37 by hson              #+#    #+#             */
/*   Updated: 2021/03/11 15:01:29 by kilee            ###   ########.fr       */
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

int		open_error(char *file)
{
	ft_putstr("minishell: ");
	ft_putstr(file);
	ft_putstr(": No such file or directory\n");
	return (-1);
}

int		no_home_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": HOME not set\n");
	return (err_num);
}
