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
		cmd = cmd->next;
	}
	return (cnt);
}

void	make_pipes(int fds[], int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
		pipe(fds + (i * 2));
}

t_cmd	*piping(t_cmd *cmd)
{
	int	fds[count_pipes() * 2];
	int	cnt_pip;
	int	i;

	cnt_pip = count_pipes();
	make_pipes(fds, cnt_pip);


	return (cmd);
}