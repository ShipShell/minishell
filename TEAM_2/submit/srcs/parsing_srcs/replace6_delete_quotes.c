/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace6_delete_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:13:41 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 15:51:25 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(t_quoting quoting)
{
	if (quoting.old_quotes != quoting.quotes)
		return (0);
	else if (quoting.escape == ON)
		return (0);
	else
		return (1);
}

static int	count_except_quotes(char *str)
{
	int			count;
	t_quoting	quoting;

	init_quoting(&quoting);
	count = 0;
	while (*str)
	{
		change_quoting(*str, &quoting);
		count += check_quotes(quoting);
		++str;
	}
	return (count);
}

static char	*trim(char *str, int count)
{
	char		*trimmed;
	t_quoting	quoting;
	int			i;

	i = 0;
	init_quoting(&quoting);
	trimmed = (char *)malloc(sizeof(char) * (count + 1));
	trimmed[count] = '\0';
	while (*str)
	{
		change_quoting(*str, &quoting);
		if (check_quotes(quoting) == 1)
		{
			trimmed[i] = *str;
			++i;
		}
		++str;
	}
	return (trimmed);
}

char		*trim_quotes(char *str)
{
	char		*trimmed;
	int			count;

	count = count_except_quotes(str);
	trimmed = trim(str, count);
	free(str);
	return (trimmed);
}
