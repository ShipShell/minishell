/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:09:19 by sonheewon         #+#    #+#             */
/*   Updated: 2021/03/12 11:27:59 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		show_prompt_title(void)
{
	ft_putstr_fd("🛳  shipshell$ ", 1);
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
		if (syntax_ok)
			exec_command();
	}
}
