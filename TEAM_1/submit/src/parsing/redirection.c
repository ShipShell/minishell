/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:47:16 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 12:53:33 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_cmd_list_redirection(void)
{
	t_cmd *cmd;

	cmd = g_cmd;
	while (cmd)
	{
		change_redir_status(cmd);
		cmd = cmd->next;
	}
}

void	change_redir_status(t_cmd *cmd)
{
	int		in_count;
	int		out_count;
	int		i;

	i = -1;
	in_count = 0;
	out_count = 0;
	while (cmd->command[++i])
	{
		if (ft_strchr("><", cmd->command[i][0]))
		{
			if (cmd->command[i][0] == '>')
				++out_count;
			else
				++in_count;
			free(cmd->command[i]);
			cmd->command[i] = NULL;
		}
		else
		{
			add_redir(cmd, i, in_count, out_count);
			in_count = 0;
			out_count = 0;
		}
	}
}
