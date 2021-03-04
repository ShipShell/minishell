#ifndef ERROR_H
# define ERROR_H

# include "parser.h"

int		num_arg_error(t_cmd *cmd, int err_num);
int		too_many_arg_error(t_cmd *cmd, int err_num);
int		no_command_error(t_cmd *cmd, int err_num);
int		no_file_error(t_cmd *cmd, int err_num);
int		not_valid_idt(t_cmd *cmd, char *arg, int err_num);
void	ft_error(void);

#endif
