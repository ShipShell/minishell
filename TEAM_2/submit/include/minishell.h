#ifndef MINISHELL_H
# define MINISHELL_H

#include "structures.h"
#include "libft.h"
#include "tester.h"

void	prompt_show(void);
void	prompt_loop(void);
void	handle_sigint(int signo);
t_env	*set_env(char *envp);
void	set_env_list(char **envp);
int		command_len(char *stdin_buf);
// t_list	*sep_to_single_command(char *stdin_buf);
void	parse_cmd_line(char *str);
void	init_quoting(t_quoting *quoting);
void	change_escape(char c, t_quoting *quoting);
void	change_quoting(char c, t_quoting *quoting);
// t_data	*sep_to_token(char *single_cmd);

/*
**	실행함수.
*/


#endif