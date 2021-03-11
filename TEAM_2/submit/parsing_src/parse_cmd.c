/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/11 12:46:55 by hyeonkim         ###   ########.fr       */
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
** STEP 1
** sep_to_single_cmd
** : cut cmdline by ";|" and save as single_cmd_list(t_list *)
**
** STEP 2
** tokenize
** : cut single_cmd_list->single_cmd(char *) by ' '
** and save as tokenized_single_cmd_list(t_list *)
**
** STEP 3
** replace token with special character(ex. $, ~, etc)
**
*/

t_list			*parse_cmd_line(char *str)
{
	t_list		*list_to_handle;
	t_list		*tokenized_single_cmd_list;
	t_list		*single_cmd_list;

	if (check_syntax_error(str))
	{
		return (NULL);
	}
	single_cmd_list = sep_to_single_cmd(str); // STEP 1
	tokenized_single_cmd_list = tokenize(single_cmd_list); // STEP 2
	list_to_handle = tokenized_single_cmd_list;
	replace_token_list(list_to_handle); // STEP 3
	// list_to_handle = tokenized_single_cmd_list;
	// handle_redirection(list_to_handle);
	return (tokenized_single_cmd_list);
}
