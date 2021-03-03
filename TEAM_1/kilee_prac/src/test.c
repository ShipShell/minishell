/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:52:31 by kilee             #+#    #+#             */
/*   Updated: 2021/03/02 19:46:41 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_parse_cmd_from_input(t_cmd *cmds)
{
	while (cmds)
	{
		int i = -1;
		printf("CMD%d: { ", i + 1);
		while(cmds->command[++i])
			printf("`%s`, ", cmds->command[i]);
		printf("}\n");
		cmds = cmds->next;
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

