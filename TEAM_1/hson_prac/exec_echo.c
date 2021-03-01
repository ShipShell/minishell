#include "minishell.h"

void	print_val(t_cmd *cmd, int i, int cnt)
{
	while (cmd->str[i])
	{
		ft_putstr(cmd->str[i]);
		if (i < cnt - 1)
			ft_putstr(" ");
		i++;
	}
}

int		exec_echo(t_cmd *cmd, t_env *env)
{
	int cnt_arg;

	cnt_arg = chk_arg_cnt(cmd);
	if (cnt_arg > 2 && ft_strcmp(cmd->str[1], "-n") == 0)
		print_val(cmd, 2, cnt_arg);
	else
	{
		print_val(cmd, 1, cnt_arg);
		write(1, "\n", 1);
	}
	return (0);
}