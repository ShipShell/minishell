#include "exec.h"
#include <errno.h>

// exit으로 끝내야할 듯.
int	call_no_home_err()
{
	ft_putstr_fd("bash: cd: HOME not set\n", 1);
	return (-1);
}

// current_dir을 PWD에 넣어준다.
int	put_env_pwd(char *current_dir, t_list *pwd_lst)
{
	char	*pwd;
	int		len;

	len = ft_strlen(current_dir);
	pwd = (char *)malloc(sizeof(char) * (len + 1));
	if (pwd == 0)
		return (-1);
	((t_env *)pwd_lst->content)->value = pwd;

	return (0);
}

// 환경변수에서 PWD를 바꿔준다.
int change_env_pwd(char *pwd)
{
	t_list	*temp_env;
	char	*tmp;

	temp_env = g_env;
	while (temp_env)
	{
		if (!ft_strncmp(((t_env *)temp_env->content)->key, "PWD", 3))
		{
			put_env_pwd(pwd, temp_env);
			break ;
		}
		temp_env = temp_env->next;
	}
	return (0);
}

// 홈 환경변수 확인 후 홈 환경변수로 이동.
int	check_home()
{
	t_list	*temp_env;
	char	*pwd;
	char	buff[MAX_BUFF];

	temp_env = g_env;
	while (temp_env)
	{
		if (!ft_strncmp(((t_env *)temp_env->content)->key, "HOME", 4))
		{
			pwd = ((t_env *)temp_env->content)->value;
			chdir(pwd);
			change_env_pwd(getcwd(buff, 1000));
		}
		temp_env = temp_env->next;
	}
	// 에러 보내자..
	if (!temp_env)
		return (call_no_home_err());
	return (0);
}

int	check_arg(t_cmd *cmd)
{
	char	*buff;

	// 에러 처리를 여기서 해야한다.
	if (chdir(cmd->token[1]) == -1);
	{
		ft_putstr_fd("bash: 1: command not found\n", 1);
		return (-1);
	}
	change_env_pwd(getcwd(buff, 1000));
	return (0);
}

// 현재 위치를 chdir을 이용해서 이동시킨다.
// 환경변수에서 PWD를 현재 위치로 바꿔준다.
// 실패나 문제가 있을시 -1리턴.
int	ft_cd(t_cmd *cmd)
{
	// 인자가 없을 때 HOME을 참조
	if (cmd->token[1] == 0)
		return(check_home());
	else
		return(check_arg(cmd));
}