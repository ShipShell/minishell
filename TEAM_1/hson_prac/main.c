#include "minishell.h"

t_env		*g_env;

t_env		*new_env(char *key, char *value)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env) * 1)))
		return (NULL);
	new->key = ft_strdup(key);
	new->val = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void		add_back_new_env(t_env **envs, t_env *new_env)
{
	t_env	*cur;

	if (*envs == NULL)
	{
		*envs = new_env;
		return ;
	}
	cur = *envs;
	while (cur->next)
		cur = cur->next;
	cur->next = new_env;
}

int main(int ac, char *av[], char **env)
{
	t_env	*lst_env;
	t_env	test_env;
	t_cmd	*cmd;
	int		ret;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd->str = (char **)malloc(sizeof(char *) * 4);
	// cmd->str[0] = "echo";
	// cmd->str[1] = "h";
	// cmd->str[2] = "i";
	// cmd->str[3] = NULL;

	// cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd = cmd->next;
	cmd->str = (char **)malloc(sizeof(char *) * 3);
	cmd->str[0] = "unset";
	cmd->str[1] = "a";
	cmd->str[2] = NULL;

	// cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd = cmd->next;
	// cmd->str = (char **)malloc(sizeof(char *) * 3);
	// cmd->str[0] = "pwd";
	// cmd->str[1] = NULL;

	cmd->next = 0;

	add_back_new_env(&lst_env, new_env("PWD", "/Users/hson/Desktop"));
	add_back_new_env(&lst_env, new_env("HOME", "/Users/hson"));
	add_back_new_env(&lst_env, new_env("a", "b"));
	add_back_new_env(&lst_env, new_env("myname", "hson"));

	// lst_env = (t_env *)malloc(sizeof(t_env));
	// lst_env->key = "PWD";
	// lst_env->val = "/Users/hson/Desktop";
	// printf("env[0] key&val : %s=%s\n\n", lst_env->key, lst_env->val);

	// lst_env->next = (t_env *)malloc(sizeof(t_env));
	// lst_env = lst_env->next;
	// lst_env->key = "HOME";
	// lst_env->val = "/Users/hson";
	// printf("env[1] key&val : %s=%s\n\n", lst_env->key, lst_env->val);

	// lst_env->next = (t_env *)malloc(sizeof(t_env));
	// lst_env = lst_env->next;
	// lst_env->key = "a";
	// lst_env->val = "b";
	// printf("env[2] key&val : %s=%s\n\n", lst_env->key, lst_env->val);

	// lst_env->next = (t_env *)malloc(sizeof(t_env));
	// lst_env = lst_env->next;
	// lst_env->key = "myname";
	// lst_env->val = "hson";
	// printf("env[3] key&val : %s=%s\n\n", lst_env->key, lst_env->val);

	// lst_env->next = 0;
	//printf("cmd : %s %s\nenv key&val : %s=%s\n\n", cmd->str[0], cmd->str[1], lst_env->key, lst_env->val);



	// ret = exec_cd(cmd, lst_env);
	// if (ret == 0)
	// 	printf("\n%d : exec_cd success\n", ret);
	// printf("changed env key&val : %s %s\n", lst_env->key, lst_env->val);

	// ret = exec_pwd(cmd);
	// if (ret == 0)
	// 	printf("\n%d : exec_pwd success\n", ret);

	// ret = exec_env(cmd, lst_env);
	// if (ret == 0)
	// 	printf("\n%d : exec_env success\n", ret);

	// ret = exec_exit(cmd);
	// printf("err_num : %d\n", ret);
	// if (ret == 0)
	// 	printf("\n%d : exec_exit success\n", ret);

	// ret = exec_echo(cmd, lst_env);
	// if (ret == 0)
	// 	printf("\n%d : exec_echo success\n", ret);

	ret = exec_unset(cmd, lst_env);
	if (ret == 0)
		printf("\n%d : exec_unset success\n", ret);

	free(cmd->str);
	free(cmd);
	free(lst_env);
	return (0);
}

// int main()
// {
// 	char buf[10];

// 	while (1)
// 	{
// 		printf("minishell>");
// 		while (1)
// 			scanf("%s", buf);
// 	}
// }