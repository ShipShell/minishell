/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 16:40:52 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_metacharacter(char c)
{
	if (c == '>')
		return (REDIR_OUT);
	else if (c == '<')
		return (REDIR_IN);
	else if (c == '|')
		return (PIPE);
	else if (c == ';')
		return (SEMICOLON);
	else
		return (0);
}

static int		count_metacharacter(char c, t_quoting quoting, int count)
{
	int			type;

	type = is_metacharacter(c);
	if ((quoting.quotes == CLOSED && quoting.old_escape == OFF) && type != 0)
		return (type);
	else if (c == ' ' || c == '\t')
		return (0);
	else
		return (-1 * count);
}

static int		too_many_metacharacter(char c, int count)
{
	if (count <= 186)
		return (0);
	else if ((count % REDIR_OUT) == 0 && (count / REDIR_OUT) < 3)
		return (0);
	else
		return (1);
}

static char		is_first_char_metacharacter(char *str)
{
	int			i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		++i;
	if (is_metacharacter(str[i]))
		return (str[i]);
	return (0);
}

int				check_syntax_error(char *str)
{
	int			count;
	int			i;
	char		c;
	t_quoting	quoting;

	init_quoting(&quoting);
	i = -1;
	count = 0;
	if ((c = is_first_char_metacharacter(str)))
		return (return_with_syntax_error(c));
	while (str[++i])
	{
		change_quoting(str[i], &quoting);
		count += count_metacharacter(str[i], quoting, count);
		if (too_many_metacharacter(str[i], count) != 0)
			return (return_with_syntax_error(str[i]));
	}
	if (quoting.quotes != CLOSED || (count != 0 && (count % 178) != 0))
		return (return_with_multiline_command(str));
	return (0);
}
