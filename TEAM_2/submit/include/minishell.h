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
// t_list	*sep_to_single_cmd(char *stdin_buf);
t_list	*parse_cmd_line(char *str);
int		check_syntax_error(char *str);
void	init_quoting(t_quoting *quoting);
void	change_escape(char c, t_quoting *quoting);
void	change_quotes(char c, t_quoting *quoting);
void	change_quoting(char c, t_quoting *quoting);
void	handle_redirection(char **token, t_cmd *cmd);
// t_list	*sep_to_single_cmd(char *str);
t_list	*tokenize(t_list *single_cmd_list);
// t_data	*sep_to_token(char *single_cmd);

// void	get_replaced_token(char **token);
void		replace_token_list(t_list *list_to_replace);
/*
**	실행함수.
*/

#endif