/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:00:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 16:33:09 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt()
{
	ft_putstr_fd("shipshell$ ", 1);
}

void	exit_by_cntl_d(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

char	*join_and_abandon(char *str1, char *str2)
{
	char	*garbage;

	if (str1 == 0 || str2 == 0)
		return (0);
	garbage = str1;
	str1 = ft_strjoin(str1, str2);
	free(garbage);
	free(str2);
	return (str1);
}

int		wait_cmd(void)
{
	char	*stdin_buf;
	t_list	*tokenized_single_cmd_list;
	char	*tmp;
	int		len;

	tmp = 0;
	show_prompt();
	while (get_next_line(0, &stdin_buf) == 0)
	{
		len = ft_strlen(stdin_buf);
		if (len)
		{
			if (tmp == 0)
				tmp = ft_strdup(stdin_buf);
			else
				tmp = join_and_abandon(tmp, stdin_buf);
		}
		if (len == 0 && tmp == 0)
			exit_by_cntl_d();
		ft_putstr_fd("  \b\b  \b\b", 1);
	}
	if (tmp != 0)
		stdin_buf = join_and_abandon(tmp, stdin_buf);
	tokenized_single_cmd_list = parse_cmd_line(stdin_buf);
	// tokenized_single_cmd_list 가 t_cmd(**command 랑 flag, exit_code가 담긴)의 연결리스트임!
	cycle_list(tokenized_single_cmd_list);
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
	if (g_child)
		ft_putstr_fd("\n", 1);
	else
	{
		ft_putstr_fd("\b\b  \b\b\n", 1);
		ft_putstr_fd("shipshell$ ", 1);
	}
	return ;
}

void	handle_sigquit(int signo)
{
	(void)signo;
	ft_putstr_fd("\b\b  \b\b", 1);
	if (g_child)
	{
		ft_putstr_fd("^\\Quit: 3\n", 1);
		g_exit_code = 131;
	}
	return ;
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