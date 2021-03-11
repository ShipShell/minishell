// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   replace.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/03/05 14:50:11 by hyeonkim          #+#    #+#             */
// /*   Updated: 2021/03/09 15:43:46 by hyeonkim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

static char	*check_and_replace(char *str)
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
		//check
		handled_len = check_replace_len(str + i, quoting);
		//replace
		tmp = replace(str + i, handled_len, &quoting);
		//join
		result = join_handled_part(result, tmp);
		i += handled_len;
	}
	free(str);
	return (result);
}

static void		get_replaced_token(t_cmd *cmd)
{
	int		i;
	char	**token;

	token = cmd->token;
	i = 0;
	while (token[i])
	{
		token[i] = check_and_replace(token[i]);
		++i;
	}
	handle_redirection(token, cmd);
}

void	replace_token_list(t_list *list_to_replace)
{
	while (list_to_replace)
	{
		get_replaced_token(((t_cmd *)(list_to_replace->content)));
		list_to_replace = list_to_replace->next;
	}
}