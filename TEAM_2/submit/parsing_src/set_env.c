/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/14 11:49:16 by mijeong          ###   ########.fr       */
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

// t_env	*set_env(char *envp)
// {
// 	t_env	*result;
// 	char	**key_value;

// 	result = (t_env *)malloc(sizeof(t_env));
// 	key_value = ft_split(envp, '=');
// 	result->key = key_value[0];
// 	result->value = key_value[1];
// 	return (result);
// }

static void	free_used_double_pointer(char **str)
{
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
}

t_env		*set_env(char *envp)
{
	t_env	*result;
	char	**key_value;

	result = (t_env *)malloc(sizeof(t_env));
	key_value = ft_split(envp, '=');
	int	i;
	i = -1;
	// while (key_value[++i])
	// {
	// 	printf("%d\n", i);
	// }
	result->key = ft_strdup(key_value[0]);
	result->value = ft_strdup(key_value[1]);
	free_used_double_pointer(key_value);
	return (result);
}
