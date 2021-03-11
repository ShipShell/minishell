/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/04 18:44:13 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "minishell.h"

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
	return (result);
}
