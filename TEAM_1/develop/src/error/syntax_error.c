/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:32:35 by kilee             #+#    #+#             */
/*   Updated: 2021/03/11 15:34:48 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		have_syntax_error(char *stdin_buf)
{
	if (too_many_semicolon(stdin_buf)
		|| too_many_right_redirection(stdin_buf)
		|| too_many_pipe(stdin_buf)
		|| too_many_left_redirection(stdin_buf))
	{
		syntax_error();
		return (TRUE);
	}
	return (FALSE);
}

void		syntax_error(void)
{
	ft_putstr("minishell: syntax error with unexpected token\n");
	g_exit_code = 258;
}

t_bool		too_many_semicolon(char *stdin_buf)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == ';')
			++count;
		else
			count = 0;
		if (count >= 2)
			return (TRUE);
		++stdin_buf;
	}
	return (FALSE);
}

t_bool		too_many_right_redirection(char *stdin_buf)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == '>')
			++count;
		else
			count = 0;
		if (count >= 3)
			return (TRUE);
		++stdin_buf;
	}
	return (FALSE);
}

t_bool		too_many_left_redirection(char *stdin_buf)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == '<')
			++count;
		else
			count = 0;
		if (count >= 3)
			return (TRUE);
		++stdin_buf;
	}
	return (FALSE);
}

t_bool		too_many_pipe(char *stdin_buf)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == '|')
			++count;
		else
			count = 0;
		if (count >= 3)
			return (TRUE);
		++stdin_buf;
	}
	return (FALSE);
}
