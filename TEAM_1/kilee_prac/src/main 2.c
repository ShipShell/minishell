/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:44 by kilee             #+#    #+#             */
/*   Updated: 2021/02/26 15:32:18 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_env	*g_env;
t_cmd	*g_cmd;

void	parse_cmd_from_input(char **stdin_buf)
{
	char	**tokens;

	tokens = ft_split(*stdin_buf, " ");
	add_back_new_cmd(&g_cmd, new_cmd(tokens));
}

int		show_prompt_title(void)
{
	ft_putstr_fd("shipshell$ ", 1);
	return (0);
}

void	get_prompt_input(char **stdin_buffer)
{
	get_next_line(0, stdin_buffer);
}

int		init_prompt(void)
{
	char	*stdin_buffer;
	int		input_byte;

	show_prompt_title();
	get_prompt_input(&stdin_buffer);
	parse_cmd_from_input(&stdin_buffer);
	if (ft_strncmp(stdin_buffer, "exit", 4) == 0)
	{
		test_parse_cmd_from_input(g_cmd);
		exit (0);
	}
	free(stdin_buffer);
	return (0);
}

void	loop_prompt(void)
{
	while (1)
		init_prompt();
}
void	erase_signal_ascii(void)
{
	ft_printf("\b\b  \b\b\n");
}

void	handle_sigint(int signo)
{
	erase_signal_ascii();
	show_prompt_title();
	return ;
}

void	make_envp_to_t_env(char *envpi)
{
	char	**key_value;

	key_value = ft_split(envpi, "=");
	add_back_new_env(&g_env, new_env(key_value));
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
	init_g_env(envp);
	test_init_g_env(g_env);
	signal(SIGINT, handle_sigint);
	loop_prompt();
	return (0);
}