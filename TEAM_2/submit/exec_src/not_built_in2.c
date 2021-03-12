/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_built_in2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:43 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:31:44 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**split_path(void)
{
	t_list	*env;

	env = g_env;
	while (env)
	{
		if (!ft_strcmp(((t_env *)env->content)->key, "PATH"))
			break ;
		env = env->next;
	}
	return (ft_split(((t_env *)env->content)->value, ':'));
}

char	**connect_env_key_value(void)
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
