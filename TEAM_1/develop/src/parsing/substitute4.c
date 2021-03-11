/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:14:12 by kilee             #+#    #+#             */
/*   Updated: 2021/03/11 16:50:59 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push_exit_code_to_buffer(char **buffer)
{
	char	*exit_code_str;
	int		i;

	exit_code_str = ft_itoa(g_exit_code);
	i = -1;
	while (exit_code_str[++i])
	{
		**buffer = exit_code_str[i];
		++*buffer;
	}
	free(exit_code_str);
	exit_code_str = NULL;
}
