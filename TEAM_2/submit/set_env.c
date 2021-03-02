/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/02/28 15:59:18 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/structures.h"
#include "include/minishell.h"

void	set_env_list(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		ft_lstadd_back(&g_env, ft_lstnew(set_env(envp[i])));
}

t_env	*set_env(char *envp)
{
	t_env	*result;
	char	**key_value;

	result = (t_env *)malloc(sizeof(t_env));
	key_value = ft_split(envp, '=');
	result->key = key_value[0];
	result->value = key_value[1];
	// free(key_value);
	return (result);
}