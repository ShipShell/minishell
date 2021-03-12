/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:05:26 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:05:43 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "structures.h"
# include "libft.h"

int	ft_env(t_cmd *cmd);
int	ft_echo(t_cmd *cmd);
int	ft_pwd(t_cmd *cmd);
int	ft_unset(t_cmd *cmd);
int	ft_exit(t_cmd *cmd);

/*
** error
*/
int	print_command_not_found_err(t_cmd *cmd, int index);
int	print_no_such_file_err(t_cmd *cmd, int index);
int	print_strerror(char *);
int	print_not_a_valid_identifier(char *str, int index);
int	cycle_list(t_list *cmd_list);

/*
** export
*/
int	ft_export(t_cmd *cmd);
int	cycle_arg(t_cmd *cmd);

/*
** cd
*/
int	ft_cd(t_cmd *cmd);
int	call_no_home_err();

/*
** not_built_in
*/
int	exec_not_built_in(t_cmd *cmd);
int	ft_not_built_in(t_cmd *cmd);

#endif
