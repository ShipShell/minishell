#include "minishell.h"

int		do_redir_in(t_redir *in)
{
	int		fd;

	while (in->file->next)
	{
		if ((fd = open(in->file->content, O_RDONLY)) == -1)
			return (open_error(in->file->content));
		if (close(fd) == -1)
			ft_error();
		in->file = in->file->next;
	}
	if ((in->fd = open(in->file->content, O_RDONLY)) == -1)
		return (open_error(in->file->content));
	in->tmp_std = dup(0);
	dup2(in->fd, 0);
	return (0);
}

int		do_redir_out(t_redir *out)
{
	int		fd;

	while (out->file->next)
	{
		fd = open(out->file->content, O_WRONLY | O_TRUNC | O_CREAT, 0666);
		if (close(fd) == -1)
			ft_error();
		out->file = out->file->next;
	}
	if (out->is_double == 1)
		out->fd = open(out->file->content, O_WRONLY | O_APPEND | O_CREAT, 0666);
	else
		out->fd = open(out->file->content, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	out->tmp_std = dup(1);
	dup2(out->fd, 1);
	return (0);
}

int		change_redir(t_cmd *cmd)
{
	if (cmd->redir_in)
		return (do_redir_in(cmd->redir_in));
	if (cmd->redir_out)
		return (do_redir_out(cmd->redir_out));
	return (0);
}

void	getback_redir(t_cmd *cmd)
{
	if (cmd->redir_in)
	{
		dup2(cmd->redir_in->tmp_std, 0);
		close(cmd->redir_in->tmp_std);
	}
	if (cmd->redir_out)
	{
		dup2(cmd->redir_out->tmp_std, 1);
		close(cmd->redir_out->tmp_std);
	}
}