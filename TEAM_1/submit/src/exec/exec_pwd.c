/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:42:18 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 13:50:21 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_pwd(t_cmd *cmd)
{
	char cwd[PATH_MAX];

	(void)cmd;
	ft_putstr(getcwd(cwd, PATH_MAX));
	write(1, "\n", 1);
	return (0);
}
