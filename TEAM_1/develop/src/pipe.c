#include "minishell.h"

int		count_pipes(void)
{
	t_cmd	*cmd;
	int		cnt;

	cmd = g_cmd;
	cnt = 0;
	while (cmd)
	{
		if (cmd->ispipe == 1)
			cnt++;
		else
			break;
		cmd = cmd->next;
	}
	return (cnt);
}

int		make_pipes(int fds[], int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
	{
		if (pipe(fds + (i * 2)) == -1)
			ft_error();
	}
	return (0);
}

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
	int		fds[count_pipes() * 2];
	int		cnt_pip;
	int		i;
	pid_t	pid[count_pipes() + 1];

	cnt_pip = count_pipes();
	make_pipes(fds, cnt_pip);
	i = -1;
	while (++i < cnt_pip + 1)
	{
		substitute_command(cmd);
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
