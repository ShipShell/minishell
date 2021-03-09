/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:55:08 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/09 23:12:06 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			init_quoting(t_quoting *quoting)
{
	quoting->escape = OFF;
	quoting->quotes = CLOSED;
	quoting->old_quotes = CLOSED;
}

void			change_quoting(char c, t_quoting *quoting)
{
	if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE)
		change_quotes(c, quoting);
	change_escape(c, quoting);
}

void			change_escape(char c, t_quoting *quoting)
{
	if (quoting->quotes != SINGLE_OPEN && quoting->escape == ON)
	{
		quoting->old_escape = quoting->escape;
		quoting->escape = OFF;
	}
	else
	{
		if (c == BACKSLASH)
		{
			if (quoting->quotes != SINGLE_OPEN && quoting->escape == OFF)
			{
				quoting->old_escape = quoting->escape;
				quoting->escape = ON;
			}
		}
		else
			quoting->old_escape = OFF;
	}
}

void			change_quotes(char c, t_quoting *quoting)
{
	if (c == SINGLE_QUOTE)
	{
		if (quoting->quotes == SINGLE_OPEN)
			quoting->quotes = CLOSED;
		else if (quoting->quotes == CLOSED)
		{
			if (quoting->old_escape == OFF)
				quoting->quotes = SINGLE_OPEN;
		}
	}
	else if (c == DOUBLE_QUOTE)
	{
		if (quoting->escape == OFF)
		{
			if (quoting->quotes == CLOSED)
				quoting->quotes = DOUBLE_OPEN;
			else if (quoting->quotes == DOUBLE_OPEN)
				quoting->quotes = CLOSED;
		}
	}
}
