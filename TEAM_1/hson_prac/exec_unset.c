#include "minishell.h"

void	remove_env(t_env *env, char *key)
{
	t_env *bef;
	t_env *next;

	bef = 0;
	while (env)
	{
		next = env->next;
		if (ft_strcmp(env->key, key) == 0)
		{
			if (bef)
				bef->next = next;
			else
				env = next;
			free(env->key);
			if (env->val)
				free(env->val);
			free(env);
			break;
		}
		bef = env;
		env = env->next;
	}
}

int		exec_unset(t_cmd *cmd, t_env *env)
{
	int	i;

	i = 1;
	while (cmd->str[i])
	{
		remove_env(env, cmd->str[i]);
		i++;
	}
	return (0);
}