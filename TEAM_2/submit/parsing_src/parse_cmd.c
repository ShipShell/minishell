/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/03 17:58:17 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int		ft_isspace(char c)
// {
// 	if (c == ' ' || c == '\t')
// 		return (1);
// 	else
// 		return (0);
// }

// static t_list	*string_to_prime_token(char *stdin_buf)
// {
// 	t_list		*prime;
// 	char		*check_tokenizable;
// 	//공백만으로 stdin을 자를 수 없어서 따옴표로 묶인 공백이나 특수문자를 먼저 판별해야 함.

// 	prime = NULL;
// 	check_tokenizable = check_quoted(stdin_buf);
// 	return (prime);
// }

//t_quoting 멤버의 상태를 결정
//void			change_quoting(t_quoting *quoting, char c)
//{
//	
//
//}

void			init_quoting(t_quoting *quoting)
{
	quoting->escape = OFF;
	quoting->quotes = CLOSED;
}

void			change_escape(char c, t_quoting *quoting)
{
	if (c == BACKSLASH)
	{
		if (quoting->quotes != SINGLE_OPEN && quoting->escape == ON)
			quoting->escape = OFF;
		else if (quoting->quotes != SINGLE_OPEN && quoting->escape == OFF)
			quoting->escape = ON;
	}
	else
	{
		if (quoting->quotes != SINGLE_OPEN && quoting->escape == ON)
			quoting->escape = OFF;
	}
}

void			change_quoting(char c, t_quoting *quoting)
{
	if (c == SINGLE_QUOTE)
	{
		if (quoting->quotes == SINGLE_OPEN)
			quoting->quotes = CLOSED;
		else if (quoting->quotes == CLOSED)
		{
			if (quoting->escape == OFF)
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
	change_escape(c, quoting);
}

static char		*tester(int i)
{
	if (i == 1)
		return ("ON");
	else if (i == 2)
		return ("OFF");
	else if (i == 3)
		return ("CLOSED");
	else if (i == 4)
		return ("SINGLE_OPEN");
	else if (i == 5)
		return ("DOUBLE_OPEN");
}

void			parse_cmd_line(char *str)
{
	t_quoting	quoting;
	int			i;

	i = -1;
	init_quoting(&quoting);
	while (str[++i])
	{
		change_quoting(str[i], &quoting);
		
		printf(" %c ) quotes : %s / escape : %s \n", str[i], tester(quoting.quotes), tester(quoting.escape));
	}
}