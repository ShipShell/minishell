/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/05 16:24:30 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		get_command_len(char *str)
{
	int			cmd_len;
	t_quoting	quoting;

	init_quoting(&quoting);
	cmd_len = 0;
	while (*str)
	{
		++cmd_len;
		change_quoting(*str, &quoting);
		if (ft_strchr(";|", *str)
			&& quoting.quotes == CLOSED && quoting.old_escape == OFF)
			break ;
		str++;
	}
	return (cmd_len);
}

static t_list	*sep_to_single_cmd(char *stdin_buf)
{
	t_list		*single_cmd_list;
	char		*single_cmd;
	int			single_cmd_len;

	single_cmd_list = NULL;
	while (*stdin_buf != '\0')
	{
		single_cmd_len = get_command_len(stdin_buf);
		single_cmd = ft_strndup(stdin_buf, single_cmd_len);
		ft_lstadd_back(&single_cmd_list, ft_lstnew(single_cmd));
		stdin_buf = stdin_buf + single_cmd_len;
	}
	return (single_cmd_list);
}

/*
** sep_to_single_cmd
** : cut cmdline by ";|" and save as single_cmd_list(t_list *)
**
** tokenize
** : cut single_cmd_list->single_cmd(char *) by ' '
** and save as tokenized_single_cmd_list(t_list *)
*/

t_list			*parse_cmd_line(char *str)
{
	t_list		*tokenized_single_cmd_list;
	t_list		*single_cmd_list;

	single_cmd_list = sep_to_single_cmd(str);
	tokenized_single_cmd_list = tokenize(single_cmd_list);
	return (tokenized_single_cmd_list);
}
