/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:32:35 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 16:05:47 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		too_many_pipe(char *stdin_buf)
{
	int			count;
	t_quoting	quoting;

	count = 0;
	init_quoting(&quoting);
	while (*stdin_buf)
	{
		if (*stdin_buf == '|' && quoting.quotes == CLOSED)
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

t_bool		new_line_error(char *stdin_buf)
{
	t_bool	is_error;

	is_error = FALSE;
	while (*stdin_buf)
	{
		if (ft_strchr("><|", *stdin_buf))
			is_error = TRUE;
		else if (*stdin_buf != ' ')
			is_error = FALSE;
		++stdin_buf;
	}
	return (is_error);
}
