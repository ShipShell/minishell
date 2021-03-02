#include "minishell.h"

char	*lst_find_env(t_env *env, char *key)
{
	while (env)
	{
		if (strcmp(env->key, key) == 0)
			return(env->val);
		env = env->next;
	}
	return (NULL);
}

void	lst_change_env(t_env *env, char *key, char *val)
{
	while (env)
	{
		if (strcmp(env->key, key) == 0)
		{
			// if (env->val)
			// 	free(env->val);
			if (val)
				env->val = strdup(val);
		}
		env = env->next;	
	}
}

int		exec_cd(t_cmd *cmd, t_env *env)
{
	char *val;
	char cwd[PATH_MAX];

	val = cmd->str[1];
//	printf("path value : %s\n", val);
	if (strlen(val) > PATH_MAX)
	{
		printf("path_max\n");
		return(-1);
	}
	if (strcmp(val, "~") == 0)
	{
		printf("path is ~\n");
		val = lst_find_env(env, "HOME");
	}
	printf("\nbefore getcwd : %s\n", getcwd(cwd, PATH_MAX));
	if (chdir(val) == -1)
		return (-1);
	else
	{
		printf("after getcwd : %s\n", getcwd(cwd, PATH_MAX));
		lst_change_env(env, "PWD", getcwd(cwd, PATH_MAX));
	}
	return (0);
}
