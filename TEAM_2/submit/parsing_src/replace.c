// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   replace.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/03/05 14:50:11 by hyeonkim          #+#    #+#             */
// /*   Updated: 2021/03/09 15:43:46 by hyeonkim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

static int	check_whether_replace_or_not(char c, t_quoting *quoting)
{
	if (c == '$' && quoting->quotes != SINGLE_OPEN && quoting->old_escape == OFF)
		return (2);
	else if (c == '~' && quoting->quotes == CLOSED && quoting->old_escape == OFF)
		return (1);
	else
		return (0);
}

static int	len_to_skip_or_replace(char *str, t_quoting *quoting)
{
	int		len;

	len = 0;
	if (str[len] && check_whether_replace_or_not(str[len], quoting) == 2)
	{
		while (ft_isalpha((int)str[++len]) || str[len] == '_')
			change_quoting(str[len], quoting);
	}
	else if (str[len] && check_whether_replace_or_not(str[len], quoting) == 1)
	{
		if (str[++len] == '/' || str[len] == '\0')
		{
			change_quoting(str[len], quoting);
			return (1);
		}
	}
	else
	{
		while (str[len] && !check_whether_replace_or_not(str[len], quoting))
		{
			++len;
			change_quoting(str[len], quoting);
		}
	}
	return (len);
}

static char	*replace_dollar(char *str, int len)
{
	int			i;
	char		*tmp;
	t_list		*env;

	env = g_env;
	i = 0;
	tmp = ft_strndup(str + 1, len - 1);
	while (env)
	{
		if (ft_strncmp(tmp, ((t_env *)(env->content))->key, len - 1) == 0)
		{
			free (tmp);
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

	env = g_env;
	i = 0;
	if (str[++i] == '\0' || str[i] == '/')
	{
		while (env)
		{
			if (ft_strncmp("HOME", ((t_env *)(env->content))->key, 4) == 0)
				return (((t_env *)(env->content))->value);
			env = env->next;
		}
	}
	return ("~");
}

static char *join_handled_part(char *result, char *str)
{
	char		*tmp;

	if (result == NULL)
		result = ft_strdup(str);
	else
	{
		tmp = result;
		result = ft_strjoin(tmp, str);
		free (tmp);
	}
	return (result);
}

static char	*replace(char *str, int i, int len, t_quoting quoting)
{
	if (check_whether_replace_or_not(str[i], &quoting) == 2 && len != 1)
		return (replace_dollar(str + i, len));
	else if (i == 0 && check_whether_replace_or_not(str[i], &quoting) == 1)
		return (replace_wave(str + i));
	else
		return (ft_strndup(str + i, len));
}

static char	*check_and_replace(char *str)
{
	int			i;
	int			handled_len;
	t_quoting	quoting;
	char		*tmp;
	char		*result;
	
	result = NULL;
	init_quoting(&quoting);
	i = 0;
	while (str[i])
	{
		change_quoting(str[i], &quoting);
		//check
		handled_len = len_to_skip_or_replace(str + i, &quoting);
		//replace
		tmp = replace(str, i, handled_len, quoting);
		//join
		result = join_handled_part(result, tmp);
		i += handled_len;
	}
	free(str);
	return (result);
}

void		get_replaced_token(char **token)
{
	int		i;

	i = 0;
	while (token[i])
	{
		token[i] = check_and_replace(token[i]);
		// printf("%s\n", token[i]);
		++i;
	}
}