#include "exec.h"

void	open_redir_in(t_cmd *cmd, t_redir *redir)
{
	redir->fd = open(redir->filename, O_RDONLY);
	if (redir->fd == -1)
		exit(1);
	cmd->re_in = redir;
	close(redir->fd);
}

void	open_redir_out(t_cmd *cmd, t_redir *redir)
{
	redir->fd = open(redir->filename, O_CREAT | O_TRUNC);
	if (redir->fd == -1)
		exit(1);
	cmd->re_out = redir;
	close(redir->fd);
}

void	open_redir_double(t_cmd *cmd, t_redir *redir)
{
	redir->fd = open(redir->filename, O_APPEND);
	if (redir->fd == -1)
		exit(1);
	cmd->re_out = redir;
	close(redir->fd);
}

void	check_redir_type(t_cmd *cmd)
{
	if (cmd->re_in)
	{
		cmd->re_in->fd = open(cmd->re_in->filename, O_RDONLY);
		cmd->re_in->tmp_fd = dup(0);
		dup2(cmd->re_in->fd, 0);
	}
	if (cmd->re_out)
	{
		if (cmd->re_out->redir_type == REDIR_DOUBLE)
			cmd->re_out->fd = open(cmd->re_out->filename, O_APPEND);
		else
			cmd->re_out->fd = open(cmd->re_out->filename, O_CREAT | O_TRUNC);
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

	redir_list = cmd->redir;
	while (redir_list)
	{
		if (((t_redir *)redir_list->content)->redir_type == REDIR_IN)
			open_redir_in(cmd, (t_redir *)redir_list->content);
		else if (((t_redir *)redir_list->content)->redir_type == REDIR_OUT)
			open_redir_out(cmd, (t_redir *)redir_list->content);
		else if (((t_redir *)redir_list->content)->redir_type == REDIR_DOUBLE)
			open_redir_double(cmd, (t_redir *)redir_list->content);
		redir_list = redir_list->next;
	}
	check_redir_type(cmd);
	return (1);
}