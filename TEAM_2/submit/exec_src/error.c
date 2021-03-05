#include "exec.h"

int	print_no_such_file_err(t_cmd *cmd, int index)
{
	ft_putstr_fd(cmd->token[index], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (0);
}

int	print_command_not_found_err(t_cmd *cmd, int index)
{
	ft_putstr_fd(cmd->token[index], 2);
	ft_putstr_fd(": command not found\n", 2);
	return (0);
}

int	print_strerror()
{
	g_exit_code = errno;
	ft_putstr_fd(strerror(errno), 2);
	exit(errno);
	return (0);
}