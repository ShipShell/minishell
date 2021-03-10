/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:42:30 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 14:13:36 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(int fds[], int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count * 2)
		close(fds[i++]);
}

void	dup_fds(int fds[], int i, int pipe_count)
{
	if (i < pipe_count)
		dup2(fds[i * 2 + 1], 1);
	if (i > 0)
		dup2(fds[(i - 1) * 2], 0);
	close_fds(fds, pipe_count);
}

void	wait_parent(int fds[], pid_t pid[], int cnt)
{
	int		status;
	int		i;

	close_fds(fds, cnt);
	i = -1;
	while (++i < cnt + 1)
		waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
}

t_cmd	*piping(t_cmd *cmd)
{
	int		fds[count_pipes(cmd) * 2];
	int		cnt_pip;
	int		i;
	pid_t	pid[count_pipes(cmd) + 1];

	cnt_pip = count_pipes(cmd);
	make_pipes(fds, cnt_pip);
	i = -1;
	while (++i < cnt_pip + 1)
	{
		substitute_command(cmd);
		substitute_redir(cmd);
		if (is_empty_cmd(cmd))
			skip();
		if ((pid[i] = fork()) == -1)
			ft_error();
		if (pid[i] == 0)
		{
			dup_fds(fds, i, cnt_pip);
			if (is_built_in(cmd->command[0]) == 1)
				exit(exec_builtin(cmd));
			exec_not_builtin(cmd);
		}
		cmd = cmd->next;
	}
	wait_parent(fds, pid, cnt_pip);
	return (cmd);
}
