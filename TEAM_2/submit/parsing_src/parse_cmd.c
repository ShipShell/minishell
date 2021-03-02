/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/02 20:19:54 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static char		*quotes_check(char *str)
{
}

static t_list	*string_to_token(char *stdin_buf)
{
	t_list		*prime;
	int			quotes;

	quotes = 0;
	
}

void			parse_cmd_line(char *stdin_buf)
{
	t_list		*primitive_token_list;
	
	primitive_token_list = string_to_token(stdin_buf);
	
}