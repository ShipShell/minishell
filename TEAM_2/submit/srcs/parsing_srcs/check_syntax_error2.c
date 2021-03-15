/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:42:35 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 17:10:44 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		return_with_syntax_error(char c)
{
	if (c == '|' || c == ';')
		printf("shipshell : syntax error near unexpected token '%c'\n", c);
	else if (c == '>' || c == '<')
		printf("shipshell : syntax error near unexpected token 'newline'\n");
	g_exit_code = 258;
	return (1);
}

int		return_with_multiline_command(char *str)
{
	int	len;

	len = ft_strlen(str);
	len -= 1;
	while (str[len] && (str[len] == ' ' || str[len] == '\t'))
		--len;
	if (str[len] == '>' || str[len] == '<')
		printf("shipshell : syntax error near unexpected token 'newline'\n");
	else
		printf("%s is multiline command\n", str);
	g_exit_code = 1;
	return (1);
}
