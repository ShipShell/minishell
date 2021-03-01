#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"
// #include <signal.h>
// #include <sys/wait.h>

#define PATH_MAX 1000

typedef struct	s_cmd
{
	char 			**str;
	struct s_cmd 	*next;
}				t_cmd;

typedef struct		s_env
{
	char 			*key;
	char 			*val;
	struct s_env	*next;
}					t_env;

char	*lst_find_env(t_env *env, char *key);
void	lst_change_env(t_env *env, char *key, char *val);

int		exec_cd(t_cmd *cmd, t_env *env);
int		exec_pwd(t_cmd *cmd);
int		exec_env(t_cmd *cmd, t_env *env);

int		chk_arg_cnt(t_cmd *cmd);
int		chk_arg_digit(char *val);
int		exec_exit(t_cmd *cmd);

void	print_val(t_cmd *cmd, int i, int cnt);
int		exec_echo(t_cmd *cmd, t_env *env);

int		num_arg_error(t_cmd *cmd, int err_num);
int		too_many_arg_error(t_cmd *cmd, int err_num);

#endif