#include "minishell.h"

int		exec_env(t_cmd *cmd, t_env *env)
{
	(void)cmd;
	while (env)
	{
		if (env->val)
		{
			ft_putstr(env->key);
			write(1,"=",1);
			ft_putstr(env->val);
			write(1,"\n",1);
		}
		env = env->next;
	}
	return (0);
}
