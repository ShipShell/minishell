/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:38:37 by hson              #+#    #+#             */
/*   Updated: 2021/03/10 13:38:53 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(void)
{
	ft_putstr("minishell: error: ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	exit(EXIT_FAILURE);
}

int		open_error(char *file)
{
	ft_putstr("minishell: ");
	ft_putstr(file);
	ft_putstr(": No such file or directory\n");
	return (-1);
}
