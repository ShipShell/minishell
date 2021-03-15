/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:36 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:31:37 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	equal_split(char *str, char **env_key_value)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '=')
			break ;
	}
	env_key_value[0] = ft_strndup(str, i);
	env_key_value[1] = ft_strndup(&(str[i + 1]), ft_strlen(str) - i);
	return (0);
}

static int	add_env(char **env_key_value)
{
	t_env	*env;

	env = is_same_env(env_key_value[0]);
	if (env)
	{
		free(env->value);
		env->value = env_key_value[1];
		return (0);
	}
	env = (t_env *)malloc(sizeof(t_env) * 1);
	if (!env)
		exit(1);
	env->key = env_key_value[0];
	env->value = env_key_value[1];
	ft_lstadd_back(&g_env, ft_lstnew(env));
	return (0);
}

static int	is_err_char(char *str)
{
	char	c;

	c = str[0];
	if (c == '=' || (c >= '0' && c <= '9') || c == '^' ||
		c == '!' || c == '@' || c == '$' || c == '%' ||
		c == '*')
	{
		ft_putstr_fd("shipshell: export: ", 2);
		print_not_a_valid_identifier(str);
		return (1);
	}
	g_exit_code = 1;
	return (0);
}

static int	check_equal_place(char *str)
{
	char	*env_key_value[2];
	int		i;

	if (is_err_char(str))
		return (-1);
	else
	{
		i = -1;
		while (str[++i])
		{
			if (str[i] == '=')
			{
				equal_split(str, env_key_value);
				break ;
			}
		}
		if (str[i] == 0)
		{
			env_key_value[0] = strdup(str);
			env_key_value[1] = 0;
		}
		add_env(env_key_value);
	}
	return (0);
}

int			cycle_arg(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->token[++i])
		check_equal_place(cmd->token[i]);
	return (1);
}
