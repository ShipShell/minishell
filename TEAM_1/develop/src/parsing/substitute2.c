/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:15:27 by kilee             #+#    #+#             */
/*   Updated: 2021/03/11 16:15:56 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*substitute_token(char *token)
{
	char		*buffer;
	char		*buffer_start;
	int			len;
	t_quoting	quoting;

	buffer = ft_calloc(BUFFER_MAX, sizeof(char));
	if (buffer == NULL)
		exit (1);
	init_quoting(&quoting);
	buffer_start = buffer;
	len = 0;
	while(*token)
	{
		len = push_char_to_buffer(&buffer, token, &quoting);
		change_quoting(&quoting, *token);
		token += len;
	}
	return (buffer_start);
}

int		push_char_to_buffer(char **buffer, char *token, t_quoting *quoting)
{
	int		action;

	action = check_substitute_action(quoting, *token);
	if (action == SUB_SPECIAL) //  - sigavold 나주엥 막아야함.
		return (substitute_special_char(buffer, token));
	else if (action == SUB_LITERAL) // action = SUB_LITERAL - sigavold 4096이상 나주엥 막아야함.
	{
		**buffer = *token;
		++*buffer;
	}
	return (1);
}

int		check_substitute_action(t_quoting *quoting, char c)
{

	if (ft_strchr("$~", c) && quoting->escape == OFF
		&& quoting->quotes != SINGLE_OPEN)
		return (SUB_SPECIAL);
	else if (c == SINGLE_QUOTE && quoting->quotes != DOUBLE_OPEN)
		return (SUB_SKIP);
	else if (c == DOUBLE_QUOTE && quoting->quotes != SINGLE_OPEN)
		return (SUB_SKIP);
	else if (c == BACKSLASH && quoting->escape == OFF)
		return (SUB_SKIP);
	else
		return (SUB_LITERAL);
}

int		substitute_special_char(char **buffer, char *token)
{
	int		len;
	char	*key;
	char	*value;

	len = 1;
	if (token[0] == '$')
	{
		if (token[len] == '?')
		{
			push_exit_code_to_buffer(buffer);
			return (2);
		}
		while(ft_isalpha(token[len]) || token[len] == '_')
			++len;
		if (len == 1)
		{
			**buffer = *token;
			++*buffer;
			return (1);
		}
		key = ft_strndup(&token[1], len - 1);
		value = find_value_match_with(key);
		push_value_to_buffer(value, buffer);
		free(key);
	}
	else if (token[0] == '~')
	{
		value = find_value_match_with("HOME");
		push_value_to_buffer(value, buffer);
	}
	return (len);
}
