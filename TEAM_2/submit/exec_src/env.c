#include "exec.h"

int	print_env(t_list *env_list)
{
	while (env_list)
	{
		if (((t_env *)env_list->content)->value)
		{
			ft_putstr_fd(((t_env *)env_list->content)->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(((t_env *)env_list->content)->value, 1);
			ft_putchar_fd('\n', 1);
		}
		env_list = env_list->next;
	}
	return (1);
}

int	ft_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->token[++i])
	{
		ft_putstr_fd("shipshell: ", 2);
		print_no_such_file_err(cmd->token[1]);
		g_exit_code = 127;
		return (-1);
	}
	print_env(g_env);
	return (1);
}
