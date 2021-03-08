#ifndef EXEC_H
# define EXEC_H

# include "parser.h"

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

void	chk_is_cmd_path(t_cmd *cmd);
char	**get_path_env();
void	free_arr(char **arr);
char	**make_env_char();
void	exec_not_builtin_sub(t_cmd *cmd, char **path);
void	exec_not_builtin(t_cmd *cmd);

int		count_pipes(void);
int		make_pipes(int fds[], int cnt);
void	close_fds(int fds[], int pipe_count);
void	dup_fds(int fds[], int i, int pipe_count);
// void	wait_parent1(int fds[], pid_t pid, int cnt);
void	wait_parent(int fds[], pid_t pid[], int cnt);
t_cmd	*piping(t_cmd *cmd);

void	do_redir_in(t_redir *in);
void	do_redir_out(t_redir *out);
void	change_redir(t_cmd *cmd);
void	getback_redir(t_cmd *cmd);

void	skip(void);
t_bool	is_empty_cmd(t_cmd *cmd);

#endif
