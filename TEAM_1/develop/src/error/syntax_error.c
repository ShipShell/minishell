/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:32:35 by kilee             #+#    #+#             */
/*   Updated: 2021/03/12 11:24:20 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		have_syntax_error(char *stdin_buf)
{
	if (too_many_semicolon(stdin_buf)
		|| too_many_right_redirection(stdin_buf)
		|| too_many_pipe(stdin_buf)
		|| too_many_left_redirection(stdin_buf)
		|| new_line_error(stdin_buf))
	{
		syntax_error();
		return (TRUE);
	}
	return (FALSE);
}

void		syntax_error(void)
{
	ft_putstr_fd("shipshell: syntax error with unexpected token\n", 2);
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
		else if (*stdin_buf != ' ')
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
		else if (*stdin_buf != ' ')
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
		else if (*stdin_buf != ' ')
			count = 0;
		if (count >= 2)
			return (TRUE);
		++stdin_buf;
	}
	return (FALSE);
}
