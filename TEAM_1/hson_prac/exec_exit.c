#include "minishell.h"

int		chk_arg_cnt(t_cmd *cmd)
{
	int i;

	i = 0;
	if (cmd->str)
	{
		while (cmd->str[i])
			i++;
		return (i);
	}
	return (0);
}

int		chk_arg_digit(char *val)
{
	int i;

	i = 0;
	if (val)
	{
		while (val[i])
		{
			if (!ft_isdigit(val[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int		exec_exit(t_cmd *cmd)
{
	int cnt_arg;
	int	isdigit;

	cnt_arg = chk_arg_cnt(cmd);
	isdigit = chk_arg_digit(cmd->str[1]);
	printf("cnt_arg : %d and isdigit : %d\n", cnt_arg, isdigit);
	if (cmd->str[1])
	{
		if (isdigit == 0)
		{
			ft_putstr("exit\n");
			exit(num_arg_error(cmd, 255));
		}
		if (cnt_arg > 2)
		{
			ft_putstr("exit\n");
			return (too_many_arg_error(cmd, 1));
		}
		printf("exit number : %d\n", ft_atoi(cmd->str[1]));
		exit(ft_atoi(cmd->str[1]));
	}
	exit(0);
	return (EXIT_SUCCESS);
}