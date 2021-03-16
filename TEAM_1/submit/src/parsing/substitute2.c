/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:15:27 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 15:40:53 by kilee            ###   ########.fr       */
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
		exit(1);
	init_quoting(&quoting);
	buffer_start = buffer;
	len = 0;
	while (*token)
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

	action = check_substitute_action(quoting, token);
	if (action == SUB_SPECIAL)
		return (substitute_special_char(buffer, token));
	else if (action == SUB_LITERAL)
	{
		**buffer = *token;
		++*buffer;
	}
	return (1);
}

int		check_substitute_action(t_quoting *quoting, char *c)
{
	if (ft_strchr("$~", *c) && quoting->escape == OFF
		&& quoting->quotes != SINGLE_OPEN)
		return (SUB_SPECIAL);
	else if (*c == SINGLE_QUOTE && quoting->quotes != DOUBLE_OPEN)
		return (SUB_SKIP);
	else if (*c == DOUBLE_QUOTE)
		return (double_quote_action(quoting));
	else if (*c == BACKSLASH)
		return (backslash_action(quoting, c));
	else
		return (SUB_LITERAL);
}

int		double_quote_action(t_quoting *quoting)
{
	if (quoting->quotes != SINGLE_OPEN && quoting->escape == OFF)
		return (SUB_SKIP);
	else
		return (SUB_LITERAL);
}

int		backslash_action(t_quoting *quoting, char *c)
{
	if (quoting->quotes == SINGLE_OPEN)
		return (SUB_LITERAL);
	else if (quoting->quotes == DOUBLE_OPEN && quoting->escape == ON)
		return (SUB_LITERAL);
	else if (quoting->quotes == DOUBLE_OPEN
			&& quoting->escape == OFF
			&& ft_strchr("\\\"$`", *(c + 1)) == 0)
		return (SUB_LITERAL);
	return (SUB_SKIP);
}
