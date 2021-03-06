#include "exec.h"

int	put_arg_to_std(t_cmd *cmd, int option, int i)
{
	if (cmd->token[i])
		ft_putstr_fd(cmd->token[i++], 1);
	while (cmd->token[i])
	{
		write(1, " ", 1);
		ft_putstr_fd(cmd->token[i++], 1);
	}
	if (!option)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	ft_echo(t_cmd *cmd)
{
	int	option;
	int	i;

	i = 1;
	option = 0;
	if (!ft_strcmp(cmd->token[i], "-n"))
	{
		option = 1;
		i++;
	}
	put_arg_to_std(cmd, option, i);
	return (0);
}
