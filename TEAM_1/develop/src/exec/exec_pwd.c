#include "minishell.h"

int		exec_pwd(t_cmd *cmd)
{
	char cwd[PATH_MAX];

	(void)cmd;
	ft_putstr(getcwd(cwd, PATH_MAX));
	write(1,"\n",1);
	return (0);
}