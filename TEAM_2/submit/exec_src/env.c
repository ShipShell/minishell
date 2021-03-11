# include "exec.h"

// arg에 문제가 없는지 확인
// 이 기능은 굳이 구현할 필요성을 못 느껴서 형태형이랑 이야기 한사바리!!
// int	check_arg(t_cmd *cmd)
// {
// 	t_list	*env_list;
// 	char	*env_key_value;

// 	env_list = g_env;
// 	while ((char *)cmd->arg->content)
// 	{
// 		env_list = g_env;
// 		env_key_value = ft_strjoin()
// 		while (((t_env *)env_list->content)->)
// 		{

// 		}
// 	}
// 	return (1); // 끝까지 가면 0 리턴.
// }

int	print_env(t_list *env_list)
{
	while (env_list)
	{
		if (((t_env *)env_list->content)->value)
		{
			ft_putstr_fd(((t_env *)env_list->content)->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(((t_env *)env_list->content)->value, 1);
			ft_putchar_fd('\n', 1);
		}
		env_list = env_list->next;
	}
	return (1);
}

// t_cmd *cmd가 굳이 필요할까는 짜면서 생각.
int ft_env(t_cmd *cmd)
{
	int		i;
	
	i = 0;
	// 인자가 환경변수에 있는지 확인.
	if (cmd->token[++i])
	{
		ft_putstr_fd("shipshell: ", 2);
		print_no_such_file_err(cmd, 1);
		g_exit_code = 127;
		return (-1);
	}
	print_env(g_env);
	return (1);
}