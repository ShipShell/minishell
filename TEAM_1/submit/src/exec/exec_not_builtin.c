/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_not_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:42:00 by hson              #+#    #+#             */
/*   Updated: 2021/03/16 12:35:47 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chk_is_cmd_path(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command[0], "/", 1) ||
		!ft_strncmp(cmd->command[0], "./", 2))
		cmd->ispath = 1;
}

char	**get_path_env(void)
{
	t_env	*env;
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

char	**make_env_char(void)
{
	t_env	*env;
	char	**res;
	char	*tmp;
	int		size;
	int		i;

	env = g_env;
	size = chk_arg_cnt_env();
	res = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (env)
	{
		if (!env->val)
		{
			env = env->next;
			continue;
		}
		tmp = ft_strjoin(env->key, "=");
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

	change_redir(cmd);
	chk_is_cmd_path(cmd);
	if (cmd->ispath == FALSE)
	{
		if (!(path = get_path_env()))
			exit(no_file_error(cmd, 127));
		exec_not_builtin_sub(cmd, path);
		free_arr(path);
		exit(no_command_error(cmd, 127));
	}
	else
	{
		execve(cmd->command[0], cmd->command, make_env_char());
		exit(no_file_error(cmd, 127));
	}
}
