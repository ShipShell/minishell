#include "exec.h"

int	is_built_in(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->token[0], "cd"))
		return (ft_cd(cmd));
	else if (!ft_strcmp(cmd->token[0], "echo"))
		return (ft_echo(cmd));
	else if (!ft_strcmp(cmd->token[0], "env"))
		return (ft_env(cmd));
	else if (!ft_strcmp(cmd->token[0], "exit"))
		return (ft_exit(cmd));
	else if (!ft_strcmp(cmd->token[0], "export"))
		return (ft_export(cmd));
	else if (!ft_strcmp(cmd->token[0], "pwd"))
		return (ft_pwd(cmd));
	else if (!ft_strcmp(cmd->token[0], "unset"))
		return (ft_unset(cmd));
	return (0);
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

int	count_pipe(t_list *cmd_list)
{
	int	result;

	result = 0;
	while (((t_cmd *)cmd_list->content)->flag == PIPELINE)
	{
		result++;
		cmd_list = cmd_list->next;
	}
	return (result);
}

int	*make_fd_piping(int size)
{
	int	i;
	int	*result;

	// printf("fd malloc size : %d\n", size);
	result = (int *)malloc(sizeof(int) * (size));
	i = 0;
	while (i < size)
	{
		// printf("piping : %d\n", i);
		pipe(&(result[i]));
		i += 2;
	}
	return (result);
}

int	connect_pipe(t_list *cmd_list, int *fd, int fd_index, int fd_size)
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
		waitpid(pid[i], &status, 0); // 자식 프로세스가 종료될때까지 기다린다.
		if (WIFEXITED(status)) // waitpid의 반환값을 사용하는 경우가 없을까??
			g_exit_code = WEXITSTATUS(status);
	}
}

int	exec_pipe(t_list **cmd_list)
{
	int		*fd;
	int		i;
	pid_t	*pid;
	int		pipe_num;

	i = -1;
	pipe_num = count_pipe(*cmd_list);
	fd = make_fd_piping(pipe_num * 2);
	if ((pid = (pid_t *)malloc(sizeof(pid_t) * (pipe_num + 1))) == 0)
		exit (1);
	while (++i < pipe_num + 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			connect_pipe(*cmd_list, fd, i * 2, pipe_num * 2);
		*cmd_list = (*cmd_list)->next;
	}
	wait_all_child(pid, pipe_num + 1, fd);
	free(fd);
	return (0);
}

int		cycle_list(t_list *cmd_list)
{
	int		result;
	pid_t	pid;
	int		status;

	while (cmd_list)
	{
		result = ((t_cmd *)cmd_list->content)->flag;
		if (result == PIPELINE)
		{
			exec_pipe(&cmd_list);
			return (0);
		}
		else
			result = exec_command((t_cmd *)cmd_list->content);
		if (result == -1)
			return (-1);
		cmd_list = cmd_list->next;
	}
	return (0);
}