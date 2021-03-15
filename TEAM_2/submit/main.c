/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:00:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 15:42:47 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt(void)
{
	ft_putstr_fd("shipshell$ ", 1);
}

void	prompt_loop(void)
{
	while(1)
		wait_cmd();
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_child = 0;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	set_env_list(envp);
	prompt_loop();
	return (0);
}