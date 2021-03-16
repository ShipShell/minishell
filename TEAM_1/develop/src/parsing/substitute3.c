/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:11:57 by kilee             #+#    #+#             */
/*   Updated: 2021/03/11 16:11:59 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push_value_to_buffer(char *value, char **buffer)
{
	int	i;

	if (value == NULL)
		return ;
	i = 0;
	while (*value)
	{
		**buffer = *value;
		++*buffer;
		++value;
	}
}

char	*find_value_match_with(char *key)
{
	t_env	*current_env;

	current_env = g_env;
	while (current_env)
	{
		if (ft_strcmp(current_env->key, key) == 0)
			break ;
		current_env = current_env->next;
	}
	if (current_env == NULL)
		return (NULL);
	else
		return (current_env->val);
}
