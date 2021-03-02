/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:00:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/02 19:10:29 by hyeonkim         ###   ########.fr       */
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

	show_prompt();
	get_next_line(0, &stdin_buf);
	if (ft_strncmp(stdin_buf, "exit", 4) == 0)
		exit(0);
	parse_cmd_line(stdin_buf);
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
	ft_putstr_fd("\b\b  \b\b\n", 1);
	ft_putstr_fd("shipshell$ ", 1);
	return ;
}

int		main(int argc, char **argv, char **envp)
{
	set_env_list(envp);
	t_list	*test;
	
	test = g_env;
	// while (test != NULL)
	// {
	// 	printf("%s\n", (char *)((t_env *)test->content)->key);
	// 	test = test->next;
	// }
	signal(SIGINT, handle_sigint);
	prompt_loop();
	return (0);
}