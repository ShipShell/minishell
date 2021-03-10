#ifndef ERROR_H
# define ERROR_H

# include "parser.h"

int		num_arg_error(t_cmd *cmd, int err_num);
int		too_many_arg_error(t_cmd *cmd, int err_num);
int		no_command_error(t_cmd *cmd, int err_num);
int		no_file_error(t_cmd *cmd, int err_num);
int		not_valid_idt(t_cmd *cmd, char *arg, int err_num);
void	ft_error(void);
int		open_error(char *file);

//syntax_error
t_bool	have_syntax_error(char *stdin_buf);
int		syntax_error(char *error_char, int err_num);
t_bool	too_many_semicolon(char *stdin_buf, char **error_char);
t_bool	too_many_right_redirection(char *stdin_buf, char **error_char);
t_bool	too_many_left_redirection(char *stdin_buf, char **error_char);
t_bool	too_many_pipe(char *stdin_buf, char **error_char);
t_bool	start_with_unexpected_token(void);
t_bool	unexpected_semicolon(char **error_char);
t_bool	unexpected_pipe(char **error_char);

#endif
