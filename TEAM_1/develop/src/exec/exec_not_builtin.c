#include "minishell.h"

void	chk_is_cmd_path(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command[0], "/", 1) ||
		!ft_strncmp(cmd->command[0], "./", 2))
		cmd->ispath = 1;
}

char	**get_path_env()
{
	t_env 	*env;
	char	**path;
	char	*env_path;

	env = g_env;
	env_path = 0;
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
			env_path = env->val;
		env = env->next;
	}
	if (!env_path)
		return (0);
	path = ft_split(env_path, ":");
	return (path);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

char	**make_env_char()
{
	t_env	*env;
	char	**res;
	char	*tmp;
	int		size;
	int		i;

	env = g_env;
	size = chk_arg_cnt_env(env);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (env)
	{
		if (!env->val)
		{
			env = env->next;
			continue;
		}
		tmp = ft_strjoin(env->key,"=");
		res[i] = ft_strjoin(tmp, env->val);
		free(tmp);
		i++;
		env = env->next;
	}
	res[i] = 0;
	return (res);
}

void	exec_not_builtin_sub(t_cmd *cmd, char **path)
{
	char	*tmp;
	char	*path_arg;
	char	**env_arg;
	int		i;

	i = -1;
	while (path && path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		path_arg = ft_strjoin(tmp, cmd->command[0]);
		env_arg = make_env_char();
		execve(path_arg, cmd->command, env_arg);
		free(tmp);
		free(path_arg);
		free_arr(env_arg);
	}
}

void	exec_not_builtin(t_cmd *cmd)
{
	char	**path;

	// printf("ispath : %d\n", cmd->ispath);
	chk_is_cmd_path(cmd);
	if (cmd->ispath == 0)
	{
		// printf("no path\n");
		path = get_path_env();
		exec_not_builtin_sub(cmd, path);
		free_arr(path);
		exit(no_command_error(cmd, 127));
	}
	else
	{
		// printf("has path\n");;
		execve(cmd->command[0], cmd->command, make_env_char());
		exit(no_file_error(cmd, 127));
	}
}
