#include "minishell.h"

char	*lst_find_env(char *key)
{
	t_env *env;

	env = g_env;
	while (env)
	{
		if (strcmp(env->key, key) == 0)
			return(env->val);
		env = env->next;
	}
	return (NULL);
}

void	lst_change_add_env(char *key, char *val)
{
	t_env	*env;
	t_env	*last;

	env = g_env;
	while (env)
	{
		if (strcmp(env->key, key) == 0)
		{
			if (env->val)
			 	free(env->val);
			if (val)
				env->val = strdup(val);
			printf("changed env	%s=%s\n", env->key, env->val);
			return ;
		}
		printf("env		%s=%s\n", env->key, env->val);
		last = env;
		env = env->next;	
	}
	last->next = new_env(key, val);
	last = last->next;
	printf("added env	%s=%s\n", last->key, last->val);
}

int		exec_cd(t_cmd *cmd)
{
	char *val;
	char cwd[PATH_MAX];

	val = cmd->command[1];
//	printf("path value : %s\n", val);
	if (strlen(val) > PATH_MAX)
	{
		printf("path_max\n");
		return(-1);
	}
	if (strcmp(val, "~") == 0)
	{
		printf("path is ~\n");
		val = lst_find_env("HOME");
	}
	printf("\nbefore getcwd : %s\n", getcwd(cwd, PATH_MAX));
	if (chdir(val) == -1)
		return (-1);
	else
	{
		printf("after getcwd : %s\n", getcwd(cwd, PATH_MAX));
		lst_change_add_env("PWD", getcwd(cwd, PATH_MAX));
	}
	return (0);
}
