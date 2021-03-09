#include "minishell.h"

void	do_redir_in(t_redir *in)
{
	while (in->file->next)
	{
		if (open(in->file->content, O_RDONLY) == -1)
			open_error(in->file->content, 2);
		if (close(in->file->content) == -1)
			ft_error();
		in->file = in->file->next;
	}
	in->fd = open(in->file->content, O_RDWR);
	in->tmp_std = dup(0);
	dup2(in->fd, 0);
}

void	do_redir_out(t_redir *out)
{
	while (out->file->next)
	{
		open(out->file->content, O_WRONLY | O_TRUNC | O_CREAT, 0666);
		if (close(out->file->content) == -1)
			ft_error();
		out->file = out->file->next;
	}
	out->fd = open(out->file->content, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	out->tmp_std = dup(1);
	dup2(out->fd, 1);
}

void	change_redir(t_cmd *cmd)
{
	if (cmd->redir_in)
		do_redir_in(cmd->redir_in);
	if (cmd->redir_out)
		do_redir_out(cmd->redir_out);
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