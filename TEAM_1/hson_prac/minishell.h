#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define PATH_MAX 1024

typedef struct	s_cmd
{
	char 			**command;
	struct s_cmd 	*next;
}				t_cmd;

typedef struct		s_env
{
	char 			*key;
	char 			*val;
	struct s_env	*next;
}					t_env;

t_env		*g_env;
t_cmd		*g_cmd;
int			g_exit_code;

t_env		*new_env(char *key, char *value);
void		add_back_new_env(t_env **envs, t_env *new_env);

char	*lst_find_env(char *key);
void	lst_change_add_env(char *key, char *val);

int		is_built_in(char *command);
int		exec_builtin(t_cmd *cmd);
void	not_builtin_fork(t_cmd *cmd);
void	exec_command(void);

int		exec_cd(t_cmd *cmd);
int		exec_pwd(t_cmd *cmd);
int		exec_env(t_cmd *cmd);

int		chk_arg_cnt(t_cmd *cmd);
int		chk_arg_digit(char *val);
int		exec_exit(t_cmd *cmd);

void	print_val(t_cmd *cmd, int i, int cnt);
int		exec_echo(t_cmd *cmd);

void	remove_env(char *key);
int		exec_unset(t_cmd *cmd);

int		chk_arg_cnt_env();
void	ft_sort_env(t_env **env, int size);
void	print_export_sub(t_env **sort_env);
void	print_export();
void	put_env(char *str);
int		exec_export(t_cmd *cmd);

char	**get_path_env();
void	free_arr(char **arr);
char	**make_env_char();
void	exec_not_builtin_sub(t_cmd *cmd, char **path);
void	exec_not_builtin(t_cmd *cmd);

int		num_arg_error(t_cmd *cmd, int err_num);
int		too_many_arg_error(t_cmd *cmd, int err_num);
int		no_command_error(t_cmd *cmd, int err_num);
int		not_valid_idt(t_cmd *cmd, char *arg, int err_num);
void	ft_error(void);

#endif