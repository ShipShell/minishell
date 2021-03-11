/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:44 by kilee             #+#    #+#             */
/*   Updated: 2021/03/11 16:53:28 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*g_env;
t_cmd	*g_cmd;
int		g_exit_code;
t_bool	g_child = 0;

int		show_prompt_title(void)
{
	ft_putstr_fd("shipshell$ ", 1);
	return (0);
}

void	exit_with_cntl_d(void)
{
	printf("exit\n");
	exit (0);
}

void	get_prompt_input(char **stdin_buffer)
{
	char	*temp;
	int		len;

	temp = NULL;
	while (get_next_line(0, stdin_buffer) == 0)
	{
		len = ft_strlen(*stdin_buffer);
		if (temp == NULL && len == 0)
			exit_with_cntl_d();
		else if (temp == NULL)
			temp = *stdin_buffer;
		ft_printf("  \b\b  \b\b");
	}
	if (temp != NULL)
		*stdin_buffer = temp;
}

t_bool	init_prompt(void)
{
	char	*stdin_buffer;
	t_bool	syntax_ok;

	delete_cmd_list(&g_cmd, delete_data_in_cmd);
	show_prompt_title();
	get_prompt_input(&stdin_buffer);
	syntax_ok = parse_and_split_from_input(stdin_buffer);
	free(stdin_buffer);
	return (syntax_ok);
}

void	loop_prompt(void)
{
	t_bool	syntax_ok;

	while (1)
	{
		syntax_ok = init_prompt();
		// test_parse_cmd_from_input();
		// test_make_cmd_str_to_tokens();
		if (syntax_ok) // syntax_error
			exec_command();
	}
}

void	erase_signal_ascii(void)
{
	ft_printf("\b\b  \b\b\n");
}

void	handle_sigint(int signo)
{
	(void)signo;
	if (g_child == 1)
	{
		g_exit_code = 130;
		printf("\n");
	}
	else
	{
		g_exit_code = 1;
		erase_signal_ascii();
		show_prompt_title();
	}
	return ;
}

void	handle_sigquit(int signo)
{
	(void)signo;
	if (g_child == 1)
	{
		g_exit_code = 131;
		printf("Quit: 3\n");
	}
	else
		ft_printf("\b\b  \b\b");
	return ;
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

int		main(int argc, char *argv[], char *envp[])
{
	if (argc != 1)
		return (0);
	if (argv == NULL)
		return (0);
	init_g_env(envp);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	loop_prompt();
	return (0);
}
