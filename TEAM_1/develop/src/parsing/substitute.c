/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:55:40 by kilee             #+#    #+#             */
/*   Updated: 2021/03/12 11:25:10 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	substitute_command(t_cmd *cmd)
{
	int		i;
	char	*substituted_token;
	char	**command;

	command = cmd->command;
	i = 0;
	while (command[i])
	{
		if (is_pipe_or_semicolon(command[i]))
		{
			if (*command[i] == '|' && i != 0)
				cmd->ispipe = TRUE;
			free(command[i]);
			command[i] = NULL;
			break ;
		}
		substituted_token = substitute_token(command[i]);
		free(command[i]);
		command[i] = substituted_token;
		++i;
	}
}

void	substitute_redir(t_cmd *cmd)
{
	t_list	*file;

	if (cmd->isredir == FALSE)
		return ;
	if (cmd->redir_in)
	{
		file = cmd->redir_in->file;
		substitute_redir_file_list(file);
	}
	if (cmd->redir_out)
	{
		file = cmd->redir_out->file;
		substitute_redir_file_list(file);
	}
}

void	substitute_redir_file_list(t_list *file)
{
	char	*substituted_file;

	while (file)
	{
		substituted_file = substitute_token(file->content);
		free(file->content);
		file->content = substituted_file;
		file = file->next;
	}
}

t_bool	is_pipe_or_semicolon(char *token)
{
	if (*token == '|' || *token == ';' || *token == '\0')
		return (TRUE);
	return (FALSE);
}
