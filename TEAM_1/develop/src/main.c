/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:44 by kilee             #+#    #+#             */
/*   Updated: 2021/02/26 11:04:55 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		prompt_show(void)
{
	char	*stdin_buf;
	int		input_byte;

	ft_putstr_fd("shipshell$ ", 1);
	get_next_line(0, &stdin_buf);
	if (ft_strncmp(stdin_buf, "exit", 4) == 0)
		exit(0);
	ft_putstr_fd(stdin_buf, 1);
	return (0);
}

void	prompt_loop(void)
{
	while(1)
		prompt_show();
}

void	handle_sigint(int signo)
{
	ft_printf("\b\b  \b\b\n");
	ft_putstr_fd("shipshell$ ", 1);
		return ;
}

int		main(int argc, char *argv[], char *envp[])
{
	signal(SIGINT, handle_sigint);
	prompt_loop();
	return (0);
}
