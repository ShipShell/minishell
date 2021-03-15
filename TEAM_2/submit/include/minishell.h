#ifndef MINISHELL_H
# define MINISHELL_H

#include "structures.h"
#include "libft.h"  
#include "tester.h"
#include "exec.h"

void	prompt_show(void);
void	prompt_loop(void);
void	show_prompt(void);
t_env	*set_env(char *envp);
void	set_env_list(char **envp);
int		command_len(char *stdin_buf);

/*
**	cmd_cycle
*/
int		wait_cmd(void);

/*
**	signal
*/
void	handle_sigint(int signo);
void	handle_sigquit(int signo);
void	exit_by_cntl_d(void);

/*
**	parsing 대문함수
*/
t_list	*parse_cmd_line(char *str);

/*
**	syntax error 먼저 잡아내기
*/
int		check_syntax_error(char *str);

/*
**	quoting 판단
*/
void	init_quoting(t_quoting *quoting);
void	change_escape(char c, t_quoting *quoting);
void	change_quotes(char c, t_quoting *quoting);
void	change_quoting(char c, t_quoting *quoting);

/*
**	parsing STEP 1
*/
t_list	*sep_to_single_cmd(char *stdin_buf);

/*
**	parsing STEP 2
*/
t_list	*tokenize(t_list *single_cmd_list);

/*
**	parsing STEP 3 (replace)
*/
void	replace_token_list(t_list *list_to_replace); // replace 대문함수
int		check_replace_len(char *str, t_quoting quoting); // check
char	*replace(char *str, int len, t_quoting *quoting); // replace
char	*join_handled_part(char *result, char *str); // join
void	handle_redirection(char **token, t_cmd *cmd); // redirection 처리
int 	check_whether_replace(char c, t_quoting quoting); // util



/*
**	실행함수.
*/

#endif