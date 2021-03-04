/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:00:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/04 17:37:06 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
	if (ft_strncmp(stdin_buf, "exit", 4) == 0)
		exit(0);
	tokenized_single_cmd_list = parse_cmd_line(stdin_buf);
	// tokenized_single_cmd_list 가 t_cmd(**command 랑 flag, exit_code가 담긴)의 연결리스트임!
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