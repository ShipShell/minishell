/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:41:37 by hson              #+#    #+#             */
/*   Updated: 2021/03/11 15:02:05 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lst_find_env(char *key)
{
	t_env *env;

	env = g_env;
	while (env)
	{
		if (strcmp(env->key, key) == 0)
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

void	lst_change_add_env(char *key, char *val)
{
	t_env	*env;
	t_env	*last;

	env = g_env;
	while (env)
	{
		if (strcmp(env->key, key) == 0)
		{
			if (env->val)
				free(env->val);
			if (val)
				env->val = strdup(val);
			return ;
		}
		last = env;
		env = env->next;
	}
	last->next = new_env(key, val);
	last = last->next;
}

int		exec_cd(t_cmd *cmd)
{
	char *val;
	char cwd[PATH_MAX];

	if (cmd->command[1] == NULL)
		val = lst_find_env("HOME");
	else
		val = cmd->command[1];
	if (!val || val[0] == '\0')
		return (no_home_error(cmd, 1));
	if (chdir(val) == -1)
		return (no_file_error(cmd, 1));
	if (ft_strlen(val) > PATH_MAX)
		return (-1);
	else
		lst_change_add_env("PWD", getcwd(cwd, PATH_MAX));
	return (0);
}
