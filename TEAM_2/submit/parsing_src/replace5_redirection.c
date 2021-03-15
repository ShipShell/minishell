/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace5_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:04:40 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 14:51:10 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		check_redir(char *str, int *redir_check)
{
	if (*str == '>' && *redir_check == 0)
		*redir_check = REDIR_OUT;
	else if (*str == '>' && *redir_check == REDIR_OUT)
		*redir_check = REDIR_DOUBLE;
	else if (*str == '<' && *redir_check == 0)
		*redir_check = REDIR_IN;
}

static void		save_redir_list(char *token, t_list **redir_list, int *check)
{
	t_redir		*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (*token == '>' || *token == '<')
		return ;
	else
	{
		if (*check == REDIR_OUT)
		{
			redir->redir_type = REDIR_OUT;
			redir->filename = ft_strdup(token);
		}
		else if (*check == REDIR_DOUBLE)
		{
			redir->redir_type = REDIR_DOUBLE;
			redir->filename = ft_strdup(token);
		}
		else if (*check == REDIR_IN)
		{
			redir->redir_type = REDIR_IN;
			redir->filename = ft_strdup(token);
		}
		ft_lstadd_back(redir_list, ft_lstnew(redir));
		*check = 0;
	}
}

static void		save_tmp_token(char *token, t_list **tmp_token)
{
	ft_lstadd_back(tmp_token, ft_lstnew(ft_strdup(token)));
}

static char		**list_to_double_pointer(t_list *token_list)
{
	char		**token;
	t_list		*start;
	int			count;
	int			i;

	i = -1;
	count = 0;
	start = token_list;
	while (start)
	{
		++count;
		start = start->next;
	}
	token = (char **)malloc(sizeof(char *) * (count + 1));
	token[count] = NULL;
	while (token_list)
	{
		token[++i] = ft_strdup((char *)(token_list->content));
		token_list = token_list->next;
	}
	return (token);
}

void			handle_redirection(char **token, t_cmd *cmd)
{
	t_list		*redir;
	t_list		*tmp_token;
	int			i;
	int			redir_check;

	i = 0;
	redir_check = 0;
	redir = NULL;
	tmp_token = NULL;
	while (token[i])
	{
		check_redir(token[i], &redir_check);
		if (redir_check == 0)
			save_tmp_token(token[i], &tmp_token);
		else
			save_redir_list(token[i], &redir, &redir_check);
		++i;
	}
	free_used_double_pointer(cmd->token);
	cmd->token = list_to_double_pointer(tmp_token);
	free_used_str_list(tmp_token);
	cmd->redir = redir;
}
