#include "exec.h"

int	put_not_number_err(t_cmd *cmd)
{
	ft_putstr_fd("shipshell: exit: ", 1);
	ft_putstr_fd(cmd->token[1], 1);
	ft_putstr_fd(": numeric argument required\n", 1);
	exit(255);
	return (-1);
}

int put_too_many_err()
{
	ft_putstr_fd("exit\nshipshell: exit: ", 1);
	ft_putstr_fd("too many arguments\n", 1);
	g_exit_code = 1;
	return (-1);
}

// 먼저 숫자 아닐 때 에러처리, 그리고 복수 인자 에러처리.
int	ft_exit(t_cmd *cmd)
{
	if (!cmd->token[1])
	{
		g_exit_code = 0;
		exit(0);
	}
	else if (cmd->token[1][0] < '0' || cmd->token[1][0] > '9')
		return (put_not_number_err(cmd));
	else if (cmd->token[2])
		return (put_too_many_err());
	else if (cmd->token[1] && cmd->token[2] == 0)
	{
		g_exit_code = atoi(cmd->token[1]);
		exit(g_exit_code);
	}
	return (1);
}
