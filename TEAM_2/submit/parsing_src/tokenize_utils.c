/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenkize_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:03:06 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:04:02 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_tokenizable(char c, t_quoting quoting)
{
	if (ft_strchr(";|\t ", c) && quoting.quotes == CLOSED)
		return (1);
	else if (ft_strchr("><", c)
			&& quoting.quotes == CLOSED && quoting.old_escape == OFF)
		return (1);
	else
		return (0);
}

int		get_token_len(char *str)
{
	int			token_len;
	t_quoting	quoting;

	init_quoting(&quoting);
	token_len = 0;
	while (*str)
	{
		++token_len;
		change_quoting(*str, &quoting);
		if (is_tokenizable(*str, quoting))
		{
			if (token_len != 1)
				--token_len;
			break ;
		}
		str++;
	}
	return (token_len);
}

int		get_token_count(char *str)
{
	int			count;
	int			len;

	count = 0;
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		len = get_token_len(str);
		str = str + len;
		if (len != 0)
			++count;
	}
	return (count);
}
