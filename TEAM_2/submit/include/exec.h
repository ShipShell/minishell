/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:04:59 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 18:40:53 by mijeong          ###   ########.fr       */
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

/*
** error
*/
int		print_command_not_found_err(t_cmd *cmd, int index);
int		print_no_such_file_err(char *filename);
int		print_strerror(char *str);
int		print_not_a_valid_identifier(char *str);
int		cycle_list(t_list *cmd_list);
int		print_export_not_valid_identifier(char *str);

/*
** exec
*/
int		is_built_in(t_cmd *cmd);
int		exec_command(t_cmd *cmd);
int		exec_pipe_command(t_cmd *cmd);
int		count_pipe(t_list *cmd_list);
void	free_fd_pid(int *fd, pid_t *pid);

/*
** built_in_command
*/
int		ft_env(t_cmd *cmd);
int		ft_echo(t_cmd *cmd);
int		ft_pwd();
int		ft_unset(t_cmd *cmd);
int		ft_exit(t_cmd *cmd);

/*
** ridir
*/
int		ft_redir(t_cmd *cmd);
int		get_fd_back(t_cmd *cmd);
int		open_redir_in(t_cmd *cmd, t_redir *redir);

/*
** export
*/
int		ft_export(t_cmd *cmd);
int		cycle_arg(t_cmd *cmd);
t_env	*is_same_env(char *str);

/*
** cd
*/
int		ft_cd(t_cmd *cmd);
int		call_no_home_err(void);
int		put_env_pwd(char *current_dir, t_list *pwd_lst);
char	*return_oldpwd();

/*
** not_built_in
*/
int		exec_not_built_in(t_cmd *cmd);
int		ft_not_built_in(t_cmd *cmd);
char	**connect_env_key_value(void);
char	**split_path(void);

#endif
