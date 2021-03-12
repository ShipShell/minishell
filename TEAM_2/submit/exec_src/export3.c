#include "exec.h"

t_env	*is_same_env(char *str)
{
	t_list	*env;

	env = g_env;
	while (env)
	{
		if (!ft_strcmp(((t_env *)env->content)->key, str))
			return ((t_env *)env->content);
		env = env->next;
	}
	return (0);
}
