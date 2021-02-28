#ifndef MINISHELL_H
# define MINISHELL_H

#include "structures.h"

void	prompt_show(void);
void	prompt_loop(void);
void	handle_sigint(int signo);
t_env	*set_env(char *envp);
void	set_env_list(char **envp);
int		command_len(char *stdin_buf);
t_list	*sep_to_single_command(char *stdin_buf);
void	seperate_cmdline(char *stdin_buf, t_list *cmd_list);
t_data	*sep_to_token(char *single_cmd);


#endif