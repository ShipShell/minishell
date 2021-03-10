#include "minishell.h"
#include <errno.h>

//exit
int		num_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": ");
	ft_putstr(cmd->command[1]);
	ft_putstr(": numeric argument required\n");
	return (err_num);
}

int		too_many_arg_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": too many arguments\n");
	return (err_num);
}

//command not found
int		no_command_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": command not found\n");
	return (err_num);
}

//no such file or directory
int		no_file_error(t_cmd *cmd, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	if (cmd->command[1])
	{
		ft_putstr(": ");
		ft_putstr(cmd->command[1]);
	}
	ft_putstr(": No such file or directory\n");
	return (err_num);
}

//export arg error
int		not_valid_idt(t_cmd *cmd, char *arg, int err_num)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd->command[0]);
	ft_putstr(": '");
	ft_putstr(arg);
	ft_putstr("': not a valid identifierd\n");
	return (err_num);
}

void	ft_error(void)
{
	ft_putstr("minishell: error: ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	exit(EXIT_FAILURE);
}
