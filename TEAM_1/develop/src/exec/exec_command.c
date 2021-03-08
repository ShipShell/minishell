#include "minishell.h"


int		is_built_in(char *command)
{
	if (ft_strcmp(command,"echo") == 0 ||
		ft_strcmp(command,"cd") == 0 ||
		ft_strcmp(command,"pwd") == 0 ||
		ft_strcmp(command,"export") == 0 ||
		ft_strcmp(command,"unset") == 0 ||
		ft_strcmp(command,"env") == 0 ||
		ft_strcmp(command,"exit") == 0)
		return (1);
	else
		return (0);
}

int		exec_builtin(t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(cmd->command[0],"echo") == 0)
		ret = exec_echo(cmd);
	if (ft_strcmp(cmd->command[0],"cd") == 0)
		ret = exec_cd(cmd);
	if (ft_strcmp(cmd->command[0],"pwd") == 0)
		ret = exec_pwd(cmd);
	if (ft_strcmp(cmd->command[0],"export") == 0)
		ret = exec_export(cmd);
	if (ft_strcmp(cmd->command[0],"unset") == 0)
		ret = exec_unset(cmd);
	if (ft_strcmp(cmd->command[0],"env") == 0)
		ret = exec_env(cmd);
	if (ft_strcmp(cmd->command[0],"exit") == 0)
		ret = exec_exit(cmd);
	return (ret);
}

void	not_builtin_fork(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) == -1)
		ft_error();
	if (pid == 0)
		exec_not_builtin(cmd);
	else if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			g_exit_code = WEXITSTATUS(status);
	}
}

t_bool is_empty_cmd(t_cmd *cmd)
{
	if (cmd->command[0] == NULL)
		return (TRUE);
	return (FALSE);
}

void	skip(void)
{
	return ;
}

void	exec_command(void)
{
	t_cmd	*cmd;

	cmd = g_cmd;
	// printf("exec_command cmd : %s\n", cmd->command[0]);
	while (cmd)
	{
		substitute_command(cmd);
		// test_make_cmd_str_to_tokens();
		if (is_empty_cmd(cmd))
			skip();
		else if (cmd->ispipe == 1)
		{
			cmd = piping(cmd);
			continue;
		}
		else if (is_built_in(cmd->command[0]) == 1)
			g_exit_code = exec_builtin(cmd);
		else
			not_builtin_fork(cmd);
		cmd = cmd->next;
	}
}
