#include "minishell.h"

int main(int ac, char *av[], char **env)
{
	t_cmd	*cmd;
	t_env	*lst_env;
	int		ret;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	lst_env = (t_env *)malloc(sizeof(t_env));
	cmd->str = (char **)malloc(sizeof(char *) * 3);
	cmd->str[0] = "echo";
	cmd->str[1] = "h";
	cmd->str[2] = "i";
	//md->str[3] = NULL;
	cmd->next = 0;

	lst_env->key = "PWD";
	lst_env->val = "/Users/hson";
	lst_env->next = 0;
	printf("cmd : %s %s\nenv key&val : %s=%s\n\n", cmd->str[0], cmd->str[1], lst_env->key, lst_env->val);

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

	ret = exec_echo(cmd, lst_env);
	if (ret == 0)
		printf("\n%d : exec_echo success\n", ret);

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