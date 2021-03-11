#include "exec.h"

// PATH는 무조건 있다고 가정.
// split 실패시 0리턴일듯.
static char	**split_path()
{
	t_list	*env;

	env = g_env;
	while (env)
	{
		if (!ft_strcmp(((t_env *)env->content)->key, "PATH"))
			break;
		env = env->next;
	}
	return (ft_split(((t_env *)env->content)->value, ':'));
}

static char	**connect_env_key_value()
{
	t_list	*env;
	char	**result;
	char	*temp;
	int		i;

	result = (char **)malloc(sizeof(char *) * (ft_lstsize(g_env) + 1));
	result[ft_lstsize(g_env)] = 0;
	i = -1;
	env = g_env;
	if (result == 0)
		return (0);
	while (env)
	{
		if (((t_env *)env->content)->value)
			temp = ft_strjoin(((t_env *)env->content)->key, "=");
		else
			temp = ft_strdup(((t_env *)env->content)->key);
		result[++i] = ft_strjoin(temp, ((t_env *)env->content)->value);
		free(temp);
		env = env->next;
	}
	return (result);
}

int	ft_free_dptr(char **dptr)
{
	int	i;

	i = -1;
	while (dptr[++i])
		free(dptr[i]);
	free(dptr);
	return (0);
}

// 여러 path를 도는 함수.
int	cycle_path(t_cmd *cmd, char **path)
{
	char	**env;
	char	*path_and_cmd;
	char	*temp;
	int		i;

	i = -1;
	env = connect_env_key_value();
	if (path == 0 || env == 0)
		return (-1);
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		path_and_cmd = ft_strjoin(temp, cmd->token[0]);
		execve(path_and_cmd, cmd->token, env);
		free(temp);
		free(path_and_cmd);
	}
	ft_free_dptr(env);
	ft_putstr_fd("shipshell: ", 2);
	print_command_not_found_err(cmd, 0);
	exit(127);
	return (1);
}

int	single_path(t_cmd *cmd)
{
	char	**env;

	env = connect_env_key_value();
	if (env == 0)
		return (-1);
	if (execve(cmd->token[0], cmd->token, env) == -1)
	{
		print_strerror(cmd->token[0]);
		return (-1);
	}
	ft_free_dptr(env);
	ft_putstr_fd("shipshell: ", 1);
	print_no_such_file_err(cmd->token[0]);
	exit(1);
	return (1);
}

int	exec_not_built_in(t_cmd *cmd)
{
	char	**path;

	// ft_redir(cmd);
	path = split_path();
	if (!ft_strncmp(cmd->token[0], "./", 2) 
		|| !ft_strncmp(cmd->token[0], "/", 1))
		return (single_path(cmd));
	else
		return (cycle_path(cmd, path));
}

int	ft_not_built_in(t_cmd *cmd)
{
	char	**path;
	pid_t	pid;
	int		status;
	
	g_child = 1;
	pid = fork();
	if (pid == 0)
		exec_not_built_in(cmd);
	else if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			g_exit_code = WEXITSTATUS(status);
		g_child = 0;
	}
	return (1);
}
