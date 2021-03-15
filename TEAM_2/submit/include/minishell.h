/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:06:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 13:46:20 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structures.h"
# include "libft.h"
# include "exec.h"
# include "parse.h"
# include "free.h"

void	prompt_show(void);
void	prompt_loop(void);
void	handle_sigint(int signo);
t_env	*set_env(char *envp);
void	set_env_list(char **envp);
int		command_len(char *stdin_buf);

int 	return_with_syntax_error(char c);
int 	return_with_multiline_command(char *str);

#endif
