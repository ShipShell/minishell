/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:26 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 20:47:50 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		*make_fd_piping(int size)
{
	int	i;
	int	*result;

	result = (int *)malloc(sizeof(int) * (size));
	i = 0;
	while (i < size)
	{
		pipe(&(result[i]));
		i += 2;
	}
	return (result);
}

int		connect_pipe(t_list *cmd_list, int *fd, int fd_index, int fd_size)
{
	int	i;

	if (fd_index > 0)
		dup2(fd[fd_index - 2], 0);
	if (fd_index < fd_size)
		dup2(fd[fd_index + 1], 1);
	i = -1;
	while (++i < fd_size)
		close(fd[i]);
	i = exec_pipe_command((t_cmd *)cmd_list->content);
	exit(i);
	return (0);
}

void	wait_all_child(pid_t *pid, int child_num, int *fd)
{
	int	i;
	int	status;

	i = -1;
	while (++i < (child_num - 1) * 2)
		close(fd[i]);
	i = -1;
	while (++i < child_num)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			g_exit_code = WEXITSTATUS(status);
	}
}

int		exec_pipe(t_list **cmd_list)
{
	int		*fd;
	int		i;
	pid_t	*pid;
	int		pipe_num;

	pipe_num = count_pipe(*cmd_list);
	fd = make_fd_piping(pipe_num * 2);
	if ((pid = (pid_t *)malloc(sizeof(pid_t) * (pipe_num + 1))) == 0)
		exit(1);
	i = -1;
	while (++i < pipe_num)
	{
		g_child = 1;
		pid[i] = fork();
		if (pid[i] == 0)
			connect_pipe(*cmd_list, fd, i * 2, pipe_num * 2);
		*cmd_list = (*cmd_list)->next;
	}
	pid[i] = fork();
	if (pid[i] == 0)
		connect_pipe(*cmd_list, fd, i * 2, pipe_num * 2);
	wait_all_child(pid, pipe_num + 1, fd);
	g_child = 0;
	free_fd_pid(fd, pid);
	return (0);
}

int		cycle_list(t_list *cmd_list)
{
	int		result;

	while (cmd_list)
	{
		result = ((t_cmd *)cmd_list->content)->flag;
		if (result == PIPE)
			result = exec_pipe(&cmd_list);
		else
			result = exec_command((t_cmd *)cmd_list->content);
		if (result == -1)
			return (-1);
		cmd_list = cmd_list->next;
	}
	return (0);
}
