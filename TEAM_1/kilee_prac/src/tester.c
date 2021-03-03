/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:52:31 by kilee             #+#    #+#             */
/*   Updated: 2021/03/03 17:49:13 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_parse_cmd_from_input(void)
{
	while (g_cmd)
	{
		int i = 0;
		printf("CMDs%d: {%s} \n", i, g_cmd->cmd_str);
		++i;
		g_cmd = g_cmd->next;
	}
}

void	test_init_g_env(t_env *envs)
{
	while(envs)
	{
		printf("key:%s = value:%s\n", envs->key, envs->value);
		envs = envs->next;
	}
}

void	test_make_string_to_token_list(t_list *tokens)
{
	while (tokens)
	{
		printf("token: [%s]\n", tokens->content);
		tokens = tokens->next;
	}
}

void	test_change_quoting(void)
{
	// const char	*str = "\'echo\' \"   hi  \" \\a\\b\\c";
	const char *str = "echo \" Hello ; echo 123 \\;   \" | cat -e";
	t_quoting	quoting;
	int			i;

	i = -1;
	init_quoting(&quoting);
	printf("QUOTE : 1: CLOSED / 2: SINGLE_OPEN / 3: DOUBLE_OPEN\n");
	printf("ESCAPE : 1: ON / 2: OFF\n");
	while(str[++i])
	{
		change_quoting(&quoting, str[i]);
		printf("%d)[%c]quote:%d, escape:%d\n", i, str[i], quoting.quotes, quoting.escape);
	}
}
