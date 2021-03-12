/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:32:35 by kilee             #+#    #+#             */
/*   Updated: 2021/03/12 11:24:14 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		too_many_pipe(char *stdin_buf)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == '|')
			++count;
		else if (*stdin_buf != ' ')
			count = 0;
		if (count >= 2)
			return (TRUE);
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
