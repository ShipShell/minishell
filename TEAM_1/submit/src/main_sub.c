/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:11:16 by sonheewon         #+#    #+#             */
/*   Updated: 2021/03/12 11:11:59 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	erase_signal_ascii(void)
{
	ft_printf("\b\b  \b\b\n");
}

void	make_envp_to_t_env(char *envpi)
{
	char	**key_value;

	key_value = ft_split(envpi, "=");
	add_back_new_env(&g_env, new_env(key_value[0], key_value[1]));
	ft_free_arr(key_value, 2);
}

void	init_g_env(char *envp[])
{
	int	i;

	i = -1;
	while (envp[++i])
		make_envp_to_t_env(envp[i]);
}
