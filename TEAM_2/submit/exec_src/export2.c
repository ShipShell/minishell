#include "exec.h"

static char	**equal_split(char *str)
{
	char	**result;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			break;
	}
	result = (char **)malloc(sizeof(char *) * 2);
	if (result == 0)
		return (0);
	result[0] = (char *)malloc(sizeof(char) * i);
	if (result[0] == 0)
		return (0);
	ft_strlcpy(result[0], str, i);
	result[0][i] = '\0';
	result[1] = (char *)malloc(sizeof(char) * (ft_strlen(str) - i - 1));
	if (result[1] == 0)
		return (0);
	ft_strlcpy(result[1], &(str[i + 1]), ft_strlen(str) - i - 1);
	result[1][ft_strlen(str) - i - 1] = '\0';
	return (result);
}

static int	add_env(char **env_key_value)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env) * 1);
	if (!env)
		return (-1);
	env->key = env_key_value[0];
	env->value = env_key_value[1];
	ft_lstadd_back(&g_env, ft_lstnew(env));
	return (0);
}
static int	is_err_char(char c)
{
	if (c == '=' || (c >= '0' && c <= '9') || c == '^' ||
		c == '!' || c == '@' || c == '$' || c == '%' ||
		c == '*')
		return (1);
	return (0);
}

static int	check_equal_place(char *str)
{
	char	**env_key_value;
	int		i;

	if (is_err_char(str[0]))
		return (-1);
	else
	{
		i = -1;
		while (str[++i])
		{
			if (str[i] == '=')
				break;
		}
		env_key_value = equal_split(str);
		if (env_key_value == 0)
			return (-1);
		// = 이 있는지 없는지 확인하기.
		if (str[i] == 0)
		{
			free(env_key_value[1]);
			env_key_value[1] = 0;
		}
		add_env(env_key_value);
	}
	return (0);
}

int	cycle_arg(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->token[++i])
		check_equal_place(cmd->token[i]);
	return (0);
}