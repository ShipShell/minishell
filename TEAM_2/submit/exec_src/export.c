#include "exec.h"

char	**equal_split(char *str)
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

int	add_env(char **env_key_value)
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
int	is_err_char(char c)
{
	if (c == '=' || (c >= '0' && c <= '9') || c == '^' ||
		c == '!' || c == '@' || c == '$' || c == '%' ||
		c == '*')
		return (1);
	return (0);
}

int	check_equal_place(char *str)
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

int	sort_env_add(t_env *env, int len)
{
	int		i;
	int		j;
	t_env	temp;

	i = 0;
	while (++i <= len)
	{
		j = -1;
		while (++j < len - i)
		{
			if (ft_strcmp(env[j].key, env[j + 1].key) >= 0)
			{
				if (ft_strcmp(env[j].key, env[j + 1].key) == 0 && ft_strcmp(env[j].value, env[j + 1].value) <= 0)
					continue;
				temp = env[j];
				env[j] = env[j + 1];
				env[j + 1] = temp;
			}
		}
	}
	return (0);
}

// int	free_sorted_env(char **env)
// {
// 	int	i;

// 	i = -1;
// 	while (env[++i])
// 		free(env[i]);
// 	free(env);
// 	return (0);
// }

t_env	*sort_env()
{
	t_env	*env;
	t_list	*temp_g_env;
	int		i;

	i = ft_lstsize(g_env);
	env = (t_env *)malloc(sizeof(t_env) * i);
	if (env == 0)
		return (0);
	temp_g_env = g_env;
	while (temp_g_env)
	{
		env[--i].key = ((t_env *)temp_g_env->content)->key;
		env[--i].value = ((t_env *)temp_g_env->content)->value;
		temp_g_env = temp_g_env->next;
	}
	sort_env_add(env, ft_lstsize(g_env));
	return (env);
}

int	export_no_arg()
{
	int		i;
	t_list	*env_list;
	t_env	*sorted_env;

	i = -1;
	env_list = g_env;
	sorted_env = sort_env();
	while (sorted_env[++i].key)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(sorted_env[i].key, 1);
		if (sorted_env[i].value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(sorted_env[i].value, 1);
			ft_putstr_fd("\"\n", 1);
		}
		else
			;
		env_list = env_list->next;
	}
	return (0);
}

int	export(t_cmd *cmd)
{
	if (!cmd->token[1])
		return (export_no_arg());
	else
		return (cycle_arg(cmd));
}