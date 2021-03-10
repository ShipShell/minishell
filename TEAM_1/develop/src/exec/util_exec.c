/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:00:35 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 14:01:02 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

t_bool	is_empty_cmd(t_cmd *cmd)
{
	if (cmd->command[0] == NULL)
		return (TRUE);
	return (FALSE);
}

void	skip(void)
{
	return ;
}
