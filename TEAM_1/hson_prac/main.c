#include "minishell.h"

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
	t_cmd	*cmd;
	int		ret;

	g_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	g_cmd->command = (char **)malloc(sizeof(char *) * 3);
	g_cmd->command[0] = "unset";
	g_cmd->command[1] = "PWD";
	//g_cmd->command[2] = "3";
	g_cmd->command[2] = NULL;
	g_cmd->ispath = 0;
	g_cmd->next = 0;

	cmd = g_cmd;

	// cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd = cmd->next;
	// cmd->command = (char **)malloc(sizeof(char *) * 4);
	// cmd->command[0] = "exit";
	// cmd->command[1] = "1";
	// cmd->command[2] = "2";
	// cmd->command[3] = NULL;

	add_back_new_env(&g_env, new_env("PWD", "/Users/hson/Desktop"));
	add_back_new_env(&g_env, new_env("HOME", "/Users/hson"));
	add_back_new_env(&g_env, new_env("myname", "hson"));
	add_back_new_env(&g_env, new_env("b", "\"hihi\""));
	add_back_new_env(&g_env, new_env("a", "b"));

	//printf("cmd : %s %s\nenv key&val : %s=%s\n\n", cmd->command[0], cmd->command[1], lst_env->key, lst_env->val);

	exec_command();
	printf("\nexec_%s success\n", g_cmd->command[0]);
	printf("excode : %d \n", g_exit_code);

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

	// ret = exec_unset(cmd, lst_env);
	// if (ret == 0)
	// 	printf("\n%d : exec_unset success\n", ret);
	
	// ret = exec_export(cmd);
	// if (ret == 0)
	// 	printf("\n%d : exec_export success\n", ret);

	free(cmd->command);
	free(cmd);
	free(g_env);
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