/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:32:35 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 16:05:19 by kilee            ###   ########.fr       */
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
	int			count;
	t_quoting	quoting;

	count = 0;
	init_quoting(&quoting);
	while (*stdin_buf)
	{
		if (*stdin_buf == ';' && quoting.quotes == CLOSED)
			++count;
		else if (*stdin_buf != ' ')
			count = 0;
		if (count >= 2)
			return (TRUE);
		change_quoting(&quoting, *stdin_buf);
		++stdin_buf;
	}
	return (FALSE);
}

t_bool		too_many_right_redirection(char *stdin_buf)
{
	int			count;
	t_quoting	quoting;

	count = 0;
	init_quoting(&quoting);
	while (*stdin_buf)
	{
		if (*stdin_buf == '>' && quoting.quotes == CLOSED)
			++count;
		else if (*stdin_buf != ' ')
			count = 0;
		if (count >= 3)
			return (TRUE);
		change_quoting(&quoting, *stdin_buf);
		++stdin_buf;
	}
	return (FALSE);
}

t_bool		too_many_left_redirection(char *stdin_buf)
{
	int			count;
	t_quoting	quoting;

	count = 0;
	init_quoting(&quoting);
	while (*stdin_buf)
	{
		if (*stdin_buf == '<' && quoting.quotes == CLOSED)
			++count;
		else if (*stdin_buf != ' ')
			count = 0;
		if (count >= 2)
			return (TRUE);
		change_quoting(&quoting, *stdin_buf);
		++stdin_buf;
	}
	return (FALSE);
}
