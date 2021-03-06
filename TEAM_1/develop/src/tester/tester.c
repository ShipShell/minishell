/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:52:31 by kilee             #+#    #+#             */
/*   Updated: 2021/03/05 15:17:49 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_parse_cmd_from_input(void)
{
	t_cmd *current_cmd;

	current_cmd = g_cmd;
	while (current_cmd)
	{
		int i = 0;
		printf("CMDs%d: {%s} \n", i, current_cmd->cmd_str);
		++i;
		current_cmd = current_cmd->next;
	}
}

void	test_init_g_env(t_env *envs)
{
	while(envs)
	{
		printf("key:%s = value:%s\n", envs->key, envs->val);
		envs = envs->next;
	}
}

void	test_make_cmd_str_to_tokens(void)
{
	t_cmd	*current_cmd;
	int		i;

	current_cmd = g_cmd;
	while (current_cmd)
	{
		printf("CMD : {");
		i = 0;
		while (current_cmd->command[i])
			printf("[%s], ", current_cmd->command[i++]);
		printf("}\n");
		current_cmd = current_cmd->next;
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
