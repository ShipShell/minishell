/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:20:08 by sonheewon         #+#    #+#             */
/*   Updated: 2021/03/12 11:20:56 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		empty_cmd_handler(t_cmd *cmd)
{
	if (cmd->isredir == TRUE)
	{
		if (change_redir(cmd) == -1)
			return (1);
		getback_redir(cmd);
		return (0);
	}
	else
	{
		syntax_error();
		return (258);
	}
}

void	exec_default(t_cmd *cmd)
{
	if (is_empty_cmd(cmd))
		g_exit_code = empty_cmd_handler(cmd);
	else if (is_built_in(cmd->command[0]) == TRUE)
		g_exit_code = exec_builtin(cmd);
	else
		not_builtin_fork(cmd);
}

void	exec_default_pipe(t_cmd *cmd)
{
	substitute_command(cmd);
	substitute_redir(cmd);
	if (is_empty_cmd(cmd))
		exit(empty_cmd_handler(cmd));
	else if (is_built_in(cmd->command[0]) == 1)
		exit(exec_builtin(cmd));
	else
		exec_not_builtin(cmd);
}
