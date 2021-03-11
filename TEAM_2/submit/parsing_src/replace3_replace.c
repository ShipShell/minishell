#include "minishell.h"

static char	*replace_tmp_with_exit_code(char *tmp)
{
	free (tmp);
	tmp = ft_itoa(g_exit_code);
	return (tmp);
}

static char	*replace_dollar(char *str, int len)
{
	int			i;
	char		*tmp;
	t_list		*env;

	env = g_env;
	i = 0;
	tmp = ft_strndup(str + 1, len - 1);
	if (tmp[0] == '?')
		return (replace_tmp_with_exit_code(tmp));
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
	char		*tmp;

	env = g_env;
	i = 0;
	if (str[i + 1] == '\0' || str[i + 1] == '/')
	{
		while (env)
		{
			if (ft_strncmp("HOME", ((t_env *)(env->content))->key, 4) == 0)
				tmp = ft_strdup(((t_env *)(env->content))->value);
			env = env->next;
		}
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