/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/11 11:38:24 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_syntax_error(char *str)
{
	int			count;
	t_quoting	quoting;

	init_quoting(&quoting);
	count = 0;
	while (*str)
	{
		change_quoting(*str, &quoting);
		if (quoting.old_quotes != quoting.quotes)
			count = 0;
		if (quoting.quotes == CLOSED && (*str == '>' || *str == '<'))
			++count;
		else if (count > 0
			&& (*str != '>' && *str != '<' && *str != ' ' && *str != '\t'))
			--count;
		// test_change_quoting(quoting);
		if (count > 2)
		{
			printf("shipshell : syntax error near '%c'\n", *str);		
			g_exit_code = 258;
			
			return (1);
		}
		++str;
	}
	return (0);
}