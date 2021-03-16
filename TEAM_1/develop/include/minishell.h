/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:11:23 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 12:57:00 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include "utils.h"
# include "parser.h"
# include "error.h"
# include "exec.h"
# include "prompt.h"
# include "tester.h"

# define BUFFER_MAX 4096
# define PATH_MAX 1024

extern t_env	*g_env;
extern t_cmd	*g_cmd;
extern int		g_exit_code;
extern t_bool	g_child;

void	erase_signal_ascii(void);
void	make_envp_to_t_env(char *envpi);
void	init_g_env(char *envp[]);
void	handle_sigint(int signo);
void	handle_sigquit(int signo);
void	ascii_art(void);

#endif
