#include "exec.h"

static int	sort_env_add(t_env *env, int len)
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
				if (ft_strcmp(env[j].key, env[j + 1].key) == 0 &&
					ft_strcmp(env[j].value, env[j + 1].value) <= 0)
					continue;
				temp = env[j];
				env[j] = env[j + 1];
				env[j + 1] = temp;
			}
		}
	}
	return (0);
}

static t_env	*sort_env()
{
	t_env	*env;
	t_list	*temp_g_env;
	int		i;

	i = ft_lstsize(g_env);
	env = (t_env *)malloc(sizeof(t_env) * (i + 1));
	if (env == 0)
		return (0);
	temp_g_env = g_env;
	while (temp_g_env)
	{
		env[--i].key = ((t_env *)temp_g_env->content)->key;
		env[i].value = ((t_env *)temp_g_env->content)->value;
		temp_g_env = temp_g_env->next;
	}
	sort_env_add(env, ft_lstsize(g_env));
	return (env);
}

static int	export_no_arg()
{
	int		i;
	t_list	*env_list;
	t_env	*sorted_env;

	i = -1;
	env_list = g_env;
	sorted_env = sort_env();
	while (env_list)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(sorted_env[++i].key, 1);
		if (sorted_env[i].value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(sorted_env[i].value, 1);
			ft_putstr_fd("\"\n", 1);
		}
		else
			ft_putstr_fd("\n", 1);
		env_list = env_list->next;
	}
	free(sorted_env);
	return (1);
}

int	ft_export(t_cmd *cmd)
{
	if (!cmd->token[1])
		return (export_no_arg());
	else
		return (cycle_arg(cmd));
}