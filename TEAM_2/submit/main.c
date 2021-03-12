/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:00:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 12:26:47 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt()
{
	ft_putstr_fd("shipshell$ ", 1);
}

int		wait_cmd(void)
{
	char	*stdin_buf;
	t_list	*tokenized_single_cmd_list;

	show_prompt();
	get_next_line(0, &stdin_buf);
	tokenized_single_cmd_list = parse_cmd_line(stdin_buf);
	// cycle_list(tokenized_single_cmd_list);
	free(stdin_buf);
	return (0);
}

void	prompt_loop(void)
{
	while(1)
		wait_cmd();
}

void	handle_sigint(int signo)
{
	(void)signo;
	ft_putstr_fd("\b\b  \b\b\n", 1);
	ft_putstr_fd("shipshell$ ", 1);
	return ;
}

int		main(int argc, char **argv, char **envp)
{
	set_env_list(envp);
	
	(void)argc;
	(void)argv;
	signal(SIGINT, handle_sigint);
	prompt_loop();
	return (0);
}