/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:44:08 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 13:49:36 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	parse_and_split_from_input(char *stdin_buf)
{
	if (have_syntax_error(stdin_buf))
		return (FALSE);
	parse_cmd_from_input(stdin_buf);
	make_cmd_str_to_tokens();
	check_cmd_list_redirection();
	return (TRUE);
}

void	parse_cmd_from_input(char *stdin_buf)
{
	int		len;
	char	*cmd_str;

	len = 0;
	while (*stdin_buf)
	{
		skip_seperator_at_first(&stdin_buf);
		len = count_cmd_length(stdin_buf);
		if (len == 0)
			break ;
		cmd_str = ft_strndup(stdin_buf, len);
		add_back_new_cmd(&g_cmd, new_cmd(cmd_str));
		stdin_buf += len;
	}
}

void	skip_seperator_at_first(char **ptr)
{
	while (**ptr && ft_strchr(" \t", **ptr) != 0)
		(*ptr)++;
}

int		count_cmd_length(char *ptr)
{
	t_quoting	quoting;
	int			len;
	t_bool		need_to_cut;

	init_quoting(&quoting);
	len = 0;
	while (*ptr)
	{
		++len;
		need_to_cut = need_to_cut_command(&quoting, *ptr);
		change_quoting(&quoting, *ptr);
		if (need_to_cut)
			return (len);
		ptr++;
	}
	return (len);
}

t_bool	need_to_cut_command(t_quoting *quoting, char c)
{
	if ((c == ';' || c == '|') && quoting->escape == OFF
		&& quoting->quotes == CLOSED)
		return (TRUE);
	return (FALSE);
}
