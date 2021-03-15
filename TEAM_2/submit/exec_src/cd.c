#include "exec.h"

int	put_env_oldpwd(t_list *pwd_lst)
{
	t_list	*oldpwd;

	oldpwd = g_env;
	while (oldpwd)
	{
		if (!ft_strcmp(((t_env *)oldpwd->content)->key, "OLDPWD"))
		{
			free(((t_env *)oldpwd->content)->value);
			((t_env *)oldpwd->content)->value =
				((t_env *)pwd_lst->content)->value;
			break ;
		}
		oldpwd = oldpwd->next;
	}
	return (1);
}

int	change_env_pwd(char *pwd)
{
	t_list	*temp_env;

	temp_env = g_env;
	while (temp_env)
	{
		if (!ft_strcmp(((t_env *)temp_env->content)->key, "PWD"))
		{
			put_env_oldpwd(temp_env);
			put_env_pwd(pwd, temp_env);
			break ;
		}
		temp_env = temp_env->next;
	}
	return (1);
}

int	check_home(void)
{
	t_list	*temp_env;
	char	*pwd;
	char	buff[MAX_BUFF];

	temp_env = g_env;
	while (temp_env)
	{
		if (!ft_strcmp(((t_env *)temp_env->content)->key, "HOME"))
		{
			pwd = ((t_env *)temp_env->content)->value;
			chdir(pwd);
			change_env_pwd(getcwd(buff, 1000));
			return (1);
		}
		temp_env = temp_env->next;
	}
	if (!temp_env)
		return (call_no_home_err());
	return (1);
}

int	check_arg(t_cmd *cmd)
{
	char	buff[MAX_BUFF];
	int		temp;

	temp = chdir(cmd->token[1]);
	if (temp == -1)
	{
		g_exit_code = 1;
		ft_putstr_fd("shipshell: cd: ", 1);
		print_no_such_file_err(cmd->token[1]);
		return (-1);
	}
	change_env_pwd(getcwd(buff, MAX_BUFF));
	return (1);
}

int	ft_cd(t_cmd *cmd)
{
	int	result;

	if (cmd->token[1] == 0)
		result = check_home();
	else
		return (check_arg(cmd));
	return (1);
}