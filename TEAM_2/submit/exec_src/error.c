/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:31:24 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	print_no_such_file_err(char *filename)
{
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (0);
}

int	print_command_not_found_err(t_cmd *cmd, int index)
{
	ft_putstr_fd(cmd->token[index], 2);
	ft_putstr_fd(": command not found\n", 2);
	return (0);
}

int	print_not_a_valid_identifier(char *str)
{
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valisd identifier\n", 2);
	return (0);
}

int	print_strerror(char *str)
{
	g_exit_code = errno;
	ft_putstr_fd("shipshell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (0);
}
