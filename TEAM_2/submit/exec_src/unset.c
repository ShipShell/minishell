#include "exec.h"

int	del_env(t_list *before, t_list *env_list)
{
	if (before == 0)
	{
		g_env = env_list;
		free(((t_env *)env_list->content)->key);
		free(((t_env *)env_list->content)->value);
		free(env_list->content);
	}
	else
	{
		before->next = env_list->next;
		free(((t_env *)env_list->content)->key);
		free(((t_env *)env_list->content)->value);
		free(env_list->content);
	}
	return (0);
}

int	find_env(t_cmd *cmd)
{
	t_list	*env_list;
	t_list	*before;
	int		i;

	i = 0;
	while (cmd->token[++i])
	{
		before = 0;
		env_list = g_env;
		while (env_list)
		{
			if (!ft_strcmp(((t_env *)env_list->content)->key, cmd->token[i]))
			{
				del_env(before, env_list);
				break ;
			}
			before = env_list;
			env_list = env_list->next;
		}
	}
	return (0);
}

int	ft_unset(t_cmd *cmd)
{
	find_env(cmd);
	return (0);
}