/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:41:34 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 15:10:41 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_quoting(t_quoting *quoting)
{
	quoting->quotes = CLOSED;
	quoting->escape = OFF;
}

void	change_quoting(t_quoting *quoting, char c)
{
	if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE)
		change_quotes_status(quoting, c);
	if (c == BACKSLASH)
		change_escape_status(quoting);
	else if (quoting->escape == ON)
		quoting->escape = OFF;
}

void	change_escape_status(t_quoting *quoting)
{
	if (quoting->quotes != SINGLE_OPEN)
	{
		if (quoting->escape == ON)
			quoting->escape = OFF;
		else
			quoting->escape = ON;
	}
}

void	change_quotes_status(t_quoting *quoting, char c)
{
	if (c == SINGLE_QUOTE && quoting->escape == OFF)
	{
		if (quoting->quotes == CLOSED)
			quoting->quotes = SINGLE_OPEN;
		else if (quoting->quotes == SINGLE_OPEN)
			quoting->quotes = CLOSED;
	}
	else if (c == DOUBLE_QUOTE && quoting->escape == OFF)
	{
		if (quoting->quotes == CLOSED)
			quoting->quotes = DOUBLE_OPEN;
		else if (quoting->quotes == DOUBLE_OPEN)
			quoting->quotes = CLOSED;
	}
}
