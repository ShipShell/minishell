/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:44:02 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 14:04:44 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_pipes(t_cmd *cmd)
{
	int		cnt;

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
