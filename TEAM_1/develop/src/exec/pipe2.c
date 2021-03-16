/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:44:02 by hson              #+#    #+#             */
/*   Updated: 2021/03/16 12:36:15 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_is_pipe(t_cmd *cmd)
{
	int	i;

	while (cmd)
	{
		i = 0;
		while (cmd->command[i])
		{
			if (*cmd->command[i] == '|' && i != 0)
				cmd->ispipe = TRUE;
			i++;
		}
		if (cmd->ispipe == FALSE)
			break ;
		cmd = cmd->next;
	}
}

int		count_pipes(t_cmd *cmd)
{
	int	cnt;

	cnt = 0;
	while (cmd)
	{
		if (cmd->ispipe == 1)
			cnt++;
		else
			break ;
		cmd = cmd->next;
	}
	return (cnt);
}

void	make_pipes(t_cmd *cmd, int fds[], int *cnt_pip)
{
	int	i;

	*cnt_pip = count_pipes(cmd);
	i = -1;
	while (++i < *cnt_pip)
	{
		if (pipe(fds + (i * 2)) == -1)
			ft_error();
	}
}
