#include "exec.h"

int	open_redir_in(t_cmd *cmd, t_redir *redir)
{
	redir->fd = open(redir->filename, O_RDONLY, 00700);
	if (redir->fd == -1)
	{
		ft_putstr_fd("shipshell: ", 2);
		print_no_such_file_err(redir->filename);
		return (-1);
	}
	cmd->re_in = redir;
	close(redir->fd);
	return (0);
}
