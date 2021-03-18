/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace3_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:55:08 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 15:54:16 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*replace_tmp_with_exit_code(char *tmp)
{
	free(tmp);
	tmp = ft_itoa(g_exit_code);
	return (tmp);
}

static char	*not_replace_dollar(char *tmp)
{
	free(tmp);
	tmp = ft_strdup("$");
	return (tmp);
}

static char	*replace_dollar(char *str, int len)
{
	char		*tmp;
	char		*key;
	t_list		*env;

	env = g_env;
	tmp = ft_strndup(str + 1, len - 1);
	if (ft_isalpha(tmp[1]) == 0 || tmp[1] != '_')
		return (not_replace_dollar(tmp));
	if (tmp[0] == '?')
		return (replace_tmp_with_exit_code(tmp));
	while (env)
	{
		key = ((t_env *)(env->content))->key;
		if (ft_strncmp(tmp, key, ft_strlen(key)) == 0)
		{
			free(tmp);
			tmp = ft_strdup(((t_env *)(env->content))->value);
			return (tmp);
		}
		env = env->next;
	}
	free(tmp);
	tmp = ft_strdup("");
	return (tmp);
}

static char	*replace_wave(char *str)
{
	int			i;
	t_list		*env;
	char		*tmp;

	env = g_env;
	i = 0;
	if (str[i + 1] == '\0' || str[i + 1] == '/')
	{
		while (env)
		{
			if (ft_strncmp("HOME", ((t_env *)(env->content))->key, 4) == 0)
			{
				tmp = ft_strdup(((t_env *)(env->content))->value);
				break ;
			}
			env = env->next;
		}
		if (env == NULL)
			tmp = ft_strdup("");
	}
	else
		tmp = ft_strdup("~");
	return (tmp);
}

char		*replace(char *str, int len, t_quoting *quoting)
{
	char		*replaced;
	int			replace_check;
	int			i;

	i = 0;
	replace_check = check_whether_replace(*str, *quoting);
	if (str[i] == '$' && replace_check == DOLLAR_ON)
		replaced = replace_dollar(str, len);
	else if (str[i] == '~' && replace_check == WAVE_ON)
		replaced = replace_wave(str);
	else
		replaced = ft_strndup(str, len);
	while (str[i] && i < len)
	{
		change_quoting(str[i], quoting);
		++i;
	}
	return (replaced);
}
