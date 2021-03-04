#include "minishell.h"

char	**get_path_env()
{
	t_env 	*env;
	char	**path;
	char	*env_path;

	env = g_env;
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
			env_path = env->val;
		env = env->next;
	}
	if (!env_path)
		return (0);
	path = ft_split(env_path, ':');
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
	char	**ret;
	char	*tmp;
	int		size;
	int		i;

	env = g_env;
	size = chk_arg_cnt_env(env);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (env)
	{
		if (!env->val)
		{
			env = env->next;
			continue;
		}
		tmp = ft_strjoin(env->key,"=");
		ret[i] = ft_strjoin(tmp, env->val);
		free(tmp);
		i++;
		env = env->next;
	}
	ret[i] = 0;
	return (ret);
}

void	exec_not_builtin_sub(t_cmd *cmd, char **path)
{
	char	*tmp;
	char	*path_arg;
	char	**env_arg;
	int		i;

	i = -1;
	while (path[++i])
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

	path = get_path_env();
	exec_not_builtin_sub(cmd, path);
	free_arr(path);
	// command not found
	exit(no_command_error(cmd, 127));
}
