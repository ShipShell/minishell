/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:30 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 17:10:01 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		is_built_in(t_cmd *cmd)
{
	if (ft_redir(cmd) == -1)
		return (-1);
	if (!ft_strcmp(cmd->token[0], "cd"))
		ft_cd(cmd);
	else if (!ft_strcmp(cmd->token[0], "echo"))
		ft_echo(cmd);
	else if (!ft_strcmp(cmd->token[0], "env"))
		ft_env(cmd);
	else if (!ft_strcmp(cmd->token[0], "exit"))
		ft_exit(cmd);
	else if (!ft_strcmp(cmd->token[0], "export"))
		ft_export(cmd);
	else if (!ft_strcmp(cmd->token[0], "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp(cmd->token[0], "unset"))
		ft_unset(cmd);
	else
	{
		get_fd_back(cmd);
		return (0);
	}
	get_fd_back(cmd);
	return (1);
}

int		exec_command(t_cmd *cmd)
{
	int		result;

	result = is_built_in(cmd);
	if (result)
		return (result);
	else
		return (ft_not_built_in(cmd));
}

int		exec_pipe_command(t_cmd *cmd)
{
	int		result;

	result = is_built_in(cmd);
	if (result)
		return (result);
	else
		return (exec_not_built_in(cmd));
}

int		count_pipe(t_list *cmd_list)
{
	int	result;

	result = 0;
	while (((t_cmd *)cmd_list->content)->flag == PIPE)
	{
		result++;
		cmd_list = cmd_list->next;
	}
	return (result);
}

void	free_fd_pid(int *fd, pid_t *pid)
{
	free(fd);
	free(pid);
}
