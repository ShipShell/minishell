#include "minishell.h"

void	exit_by_cntl_d(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

void	handle_sigint(int signo)
{
	(void)signo;
	if (g_child)
	{
		ft_putstr_fd("\n", 1);
		g_exit_code = 130;
	}
	else
	{
		g_exit_code = 1;
		ft_putstr_fd("\b\b  \b\b\n", 1);
		ft_putstr_fd("shipshell$ ", 1);
	}
	return ;
}

void	handle_sigquit(int signo)
{
	(void)signo;
	ft_putstr_fd("\b\b  \b\b", 1);
	if (g_child)
	{
		ft_putstr_fd("^\\Quit: 3\n", 1);
		g_exit_code = 131;
	}
	return ;
}