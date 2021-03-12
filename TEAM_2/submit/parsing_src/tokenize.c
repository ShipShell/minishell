/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:35:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:03:46 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**split_single_cmd(char *str)
{
	char		**token;
	int			i;
	int			token_count;
	int			token_len;

	i = -1;
	token_count = get_token_count(str);
	token = (char **)malloc(sizeof(char *) * (token_count + 1));
	token[token_count] = NULL;
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		token_len = get_token_len(str);
		if (token_len != 0)
			token[++i] = ft_strndup(str, token_len);
		str = str + token_len;
	}
	return (token);
}

static int		check_flag(t_cmd *tokenized)
{
	int			i;

	i = 0;
	while (tokenized->token[i] && tokenized->token[i + 1])
		++i;
	if (ft_strncmp(tokenized->token[i], ";", 1) == 0)
	{
		free(tokenized->token[i]);
		tokenized->token[i] = NULL;
		return (SEMICOLON);
	}
	else if (ft_strncmp(tokenized->token[i], "|", 1) == 0)
	{
		free(tokenized->token[i]);
		tokenized->token[i] = NULL;
		return (PIPE);
	}
	else
		return (0);
}

static t_cmd	*tokenize_single_cmd(char *str)
{
	t_cmd		*tokenized_cmd;

	tokenized_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	tokenized_cmd->re_in = NULL;
	tokenized_cmd->re_out = NULL;
	tokenized_cmd->redir = NULL;
	tokenized_cmd->token = split_single_cmd(str);
	tokenized_cmd->flag = check_flag(tokenized_cmd);
	return (tokenized_cmd);
}

t_list			*tokenize(t_list *single_cmd_list)
{
	t_list		*tokenized_list;

	tokenized_list = NULL;
	while (single_cmd_list)
	{
		ft_lstadd_back(&tokenized_list,
			ft_lstnew(tokenize_single_cmd(single_cmd_list->content)));
		single_cmd_list = single_cmd_list->next;
	}
	return (tokenized_list);
}
