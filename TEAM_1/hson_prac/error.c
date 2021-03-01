#include "minishell.h"
#include <errno.h>

int		num_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->str[0]);
	ft_putstr(": ");
	ft_putstr(cmd->str[1]);
	ft_putstr(": numeric argument required\n");
	return (err_num);
}

int		too_many_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->str[0]);
	ft_putstr(": too many arguments\n");
	return (err_num);
}