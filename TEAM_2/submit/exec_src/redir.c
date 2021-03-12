#include "exec.h"

int		open_redir_out(t_cmd *cmd, t_redir *redir)
{
	redir->fd = open(redir->filename, O_CREAT | O_TRUNC | O_WRONLY, 00700);
	if (redir->fd == -1)
		return (-1);
	cmd->re_out = redir;
	close(redir->fd);
	return (0);
}

int		open_redir_double(t_cmd *cmd, t_redir *redir)
{
	redir->fd = open(redir->filename, O_APPEND | O_CREAT, 00700);
	if (redir->fd == -1)
		return (-1);
	cmd->re_out = redir;
	close(redir->fd);
	return (0);
}

void	check_redir_type(t_cmd *cmd)
{
	if (cmd->re_in)
	{
		cmd->re_in->fd = open(cmd->re_in->filename, O_RDONLY, 00700);
		cmd->re_in->tmp_fd = dup(0);
		dup2(cmd->re_in->fd, 0);
	}
	if (cmd->re_out)
	{
		if (cmd->re_out->redir_type == REDIR_DOUBLE)
			cmd->re_out->fd = open(cmd->re_out->filename,
									O_APPEND | O_CREAT, 00700);
		else
			cmd->re_out->fd = open(cmd->re_out->filename,
									O_WRONLY | O_TRUNC | O_CREAT, 00700);
		cmd->re_out->tmp_fd = dup(1);
		dup2(cmd->re_out->fd, 1);
	}
}

int		get_fd_back(t_cmd *cmd)
{
	if (cmd->re_in)
	{
		dup2(cmd->re_in->tmp_fd, 0);
		close(cmd->re_in->fd);
	}
	if (cmd->re_out)
	{
		dup2(cmd->re_out->tmp_fd, 1);
		close(cmd->re_out->fd);
	}
	return (0);
}

int		ft_redir(t_cmd *cmd)
{
	t_list	*redir_list;
	int		result;

	redir_list = cmd->redir;
	while (redir_list)
	{
		if (((t_redir *)redir_list->content)->redir_type == REDIR_IN)
			result = open_redir_in(cmd, (t_redir *)redir_list->content);
		else if (((t_redir *)redir_list->content)->redir_type == REDIR_OUT)
			result = open_redir_out(cmd, (t_redir *)redir_list->content);
		else if (((t_redir *)redir_list->content)->redir_type == REDIR_DOUBLE)
			result = open_redir_double(cmd, (t_redir *)redir_list->content);
		if (result == -1)
			return (-1);
		redir_list = redir_list->next;
	}
	check_redir_type(cmd);
	return (1);
}
