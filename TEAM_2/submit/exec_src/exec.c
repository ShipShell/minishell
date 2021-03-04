#include "exec.h"

int	is_built_in(t_cmd *cmd)
{
	if (ft_strcmp(cmd->token[0], "cd"))
		return (ft_cd(cmd));
	else if (ft_strcmp(cmd->token[0], "echo"))
		return (ft_echo(cmd));
	else if (ft_strcmp(cmd->token[0], "env"))
		return (ft_env(cmd));
	else if (ft_strcmp(cmd->token[0], "exit"))
		return (ft_exit(cmd));
	else if (ft_strcmp(cmd->token[0], "export"))
		return (ft_export(cmd));
	else if (ft_strcmp(cmd->token[0], "pwd"))
		return (ft_pwd(cmd));
	else if (ft_strcmp(cmd->token[0], "unset"))
		return (ft_unset(cmd));
	return (1);
}

int	exec_command(t_cmd *cmd)
{
	char	*command;

	command = cmd->token[0];
	if (ft_strcmp(command, "cd"))
		return (ft_cd(cmd));
	else if (ft_strcmp(command, "echo"))
		return (ft_echo(cmd));
	else if (ft_strcmp(command, "env"))
		return (ft_env(cmd));
	else if (ft_strcmp(command, "exit"))
		return (ft_exit(cmd));
	else if (ft_strcmp(command, "export"))
		return (ft_export(cmd));
	else if (ft_strcmp(command, "pwd"))
		return (ft_pwd(cmd));
	else if (ft_strcmp(command, "unset"))
		return (ft_unset(cmd));
	else
		return (ft_not_built_in(cmd));
}