/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:11:57 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 15:41:04 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		substitute_special_char(char **buffer, char *token)
{
	int		len;
	char	*value;

	len = 1;
	if (token[0] == '$')
	{
		if (token[len] == '?')
		{
			push_exit_code_to_buffer(buffer);
			return (2);
		}
		len = substitute_env_variable(buffer, token);
		if (len == 0)
			return (1);
	}
	else if (token[0] == '~')
	{
		value = find_value_match_with("HOME");
		push_value_to_buffer(value, buffer);
	}
	return (len);
}

int		substitute_env_variable(char **buffer, char *token)
{
	int		len;
	char	*key;
	char	*value;

	len = 1;
	while (ft_isalpha(token[len]) || token[len] == '_')
		++len;
	if (len == 1)
	{
		**buffer = *token;
		++*buffer;
		return (0);
	}
	key = ft_strndup(&token[1], len - 1);
	value = find_value_match_with(key);
	push_value_to_buffer(value, buffer);
	free(key);
	return (len);
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
