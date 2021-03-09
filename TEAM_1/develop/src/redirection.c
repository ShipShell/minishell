#include "minishell.h"

void	do_redir_in(t_redir *in)
{
	int		fd;

	while (in->file->next)
	{
		if ((fd = open(in->file->content, O_RDONLY)) == -1)
			open_error(in->file->content);
		if (close(fd) == -1)
			ft_error();
		in->file = in->file->next;
	}
	in->fd = open(in->file->content, O_RDWR);
	in->tmp_std = dup(0);
	dup2(in->fd, 0);
	//close(in->fd);
}

void	do_redir_out(t_redir *out)
{
	int		fd;

	while (out->file->next)
	{
		fd = open(out->file->content, O_RDWR | O_TRUNC |O_CREAT, 0666);
		if (close(fd) == -1)
			ft_error();
		out->file = out->file->next;
	}
	out->fd = open(out->file->content, O_RDWR | O_TRUNC | O_CREAT, 0666);
	printf("here redir : %d\n", out->fd);
	out->tmp_std = dup(1);
	//printf("tmp_std : %d\n", out->tmp_std);
	dup2(out->fd, 1);
	//close(out->fd);
}

void	change_redir(t_cmd *cmd)
{
	if (cmd->redir_in)
		do_redir_in(cmd->redir_in);
	if (cmd->redir_out)
		do_redir_out(cmd->redir_out);
	//printf("hi\n");

}

void	getback_redir(t_cmd *cmd)
{
	printf("here is getback\n");
	if (cmd->redir_in)
	{
		dup2(cmd->redir_in->tmp_std, 0);
		//close(cmd->redir_in->tmp_std);
	}
	if (cmd->redir_out)
	{
		dup2(cmd->redir_out->tmp_std, 1);
		printf("are u serious?\n");
		//close(cmd->redir_out->tmp_std);
	}
}