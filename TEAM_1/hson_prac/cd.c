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

int		exec_pwd(t_cmd *cmd)
{
	char cwd[PATH_MAX];

	(void)cmd;
	ft_putstr(getcwd(cwd, PATH_MAX));
	write(1,"\n",1);
	return (0);
}

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

int		chk_arg_cnt(t_cmd *cmd)
{
	int i;

	i = 0;
	if (cmd->str)
	{
		while (cmd->str[i])
			i++;
		return (i);
	}
	return (0);
}

int		chk_arg_digit(char *val)
{
	int i;

	i = 0;
	if (val)
	{
		while (val[i])
		{
			if (!ft_isdigit(val[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int		exec_exit(t_cmd *cmd)
{
	int arg_cnt;
	int	isdigit;
	int ret;

	arg_cnt = chk_arg_cnt(cmd);
	isdigit = chk_arg_digit(cmd->str[1]);
	printf("arg_cnt : %d and isdigit : %d\n", arg_cnt, isdigit);
	if (cmd->str[1])
	{
		if (isdigit == 0)
		{
			ft_putstr("exit\n");
			exit(num_arg_error(cmd, 255));
		}
		if (arg_cnt > 2)
		{
			ft_putstr("exit\n");
			return (too_many_arg_error(cmd, 1));
		}
		printf("exit number : %d\n", ft_atoi(cmd->str[1]));
		exit(ft_atoi(cmd->str[1]));
	}
	exit(0);
	return (0);
}

int main(int ac, char *av[], char **env)
{
	t_cmd	*cmd;
	t_env	*lst_env;
	int		ret;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	lst_env = (t_env *)malloc(sizeof(t_env));
	cmd->str = (char **)malloc(sizeof(char *) * 4);
	cmd->str[0] = "exit";
	cmd->str[1] = "100";
	cmd->str[2] = "12";
	cmd->str[3] = NULL;
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

	ret = exec_exit(cmd);
	printf("err_num : %d\n", ret);
	if (ret == 0)
		printf("\n%d : exec_exit success\n", ret);

	free(cmd->str);
	free(cmd);
	free(lst_env);
	return (0);
}