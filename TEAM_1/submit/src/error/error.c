/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:38:07 by hson              #+#    #+#             */
/*   Updated: 2021/04/20 14:19:08 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		no_command_error(t_cmd *cmd, int err_num)
{
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	return (err_num);
}

int		no_file_error(t_cmd *cmd, int err_num)
{
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	if (cmd->command[1])
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(cmd->command[1], 2);
	}
	ft_putstr_fd(": No such file or directory\n", 2);
	return (err_num);
}

int		not_valid_idt(t_cmd *cmd, char *arg, int err_num)
{
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(": '", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifierd\n", 2);
	return (err_num);
}

void	ft_error(void)
{
	ft_putstr_fd("shipshell: error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	print_export_not_valid_identifier(char *str)
{
	ft_putstr_fd("shipshell: export: ", 2);
	print_not_a_valid_identifier(str);
	g_exit_code = 1;
	return (0);
}
