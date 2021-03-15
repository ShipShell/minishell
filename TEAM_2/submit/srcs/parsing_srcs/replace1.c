/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:50:11 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 15:39:10 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*check_and_replace(char *str)
{
	int			i;
	int			handled_len;
	t_quoting	quoting;
	char		*tmp;
	char		*result;

	result = NULL;
	init_quoting(&quoting);
	i = 0;
	while (str[i])
	{
		handled_len = check_replace_len(str + i, quoting);
		tmp = replace(str + i, handled_len, &quoting);
		result = join_handled_part(result, tmp);
		i += handled_len;
	}
	free(str);
	return (result);
}

static void		get_replaced_token(t_cmd *cmd)
{
	int			i;
	char		**token;

	token = cmd->token;
	if (token == NULL)
		return ;
	i = 0;
	while (token[i])
	{
		token[i] = check_and_replace(token[i]);
		token[i] = trim_quotes(token[i]);
		++i;
	}
	i = 0;
	handle_redirection(token, cmd);
}

void			replace_token_list(t_list *list_to_replace)
{
	while (list_to_replace)
	{
		get_replaced_token(((t_cmd *)(list_to_replace->content)));
		list_to_replace = list_to_replace->next;
	}
}
