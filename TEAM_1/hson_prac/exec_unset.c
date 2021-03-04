#include "minishell.h"

void	remove_env(char *key)
{
	t_env *env;
	t_env *bef;
	t_env *next;

	env = g_env;
	bef = 0;
	while (env)
	{
		next = env->next;
		if (ft_strcmp(env->key, key) == 0)
		{
			if (bef)
				bef->next = next;
			else
			{
				g_env = next;
				printf("1st env %s : %s\n", g_env->key, g_env->val);
			}
			free(env->key);
			if (env->val)
				free(env->val);
			free(env);
			// printf("bef : %s=%s\n", bef->key, bef->val);
			// printf("next : %s=%s\n", next->key, next->val);
			break;
		}
		bef = env;
		env = env->next;
	}
}

int		exec_unset(t_cmd *cmd)
{
	t_env	*env;
	int		i;

	env = g_env;
	i = 1;
	while (cmd->command[i])
	{
		remove_env(cmd->command[i]);
		i++;
	}
	return (0);
}