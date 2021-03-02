# include "exec.h"

// arg에 문제가 없는지 확인
// 이 기능은 굳이 구현할 필요성을 못 느껴서 형태형이랑 이야기 한사바리!!
// int	check_arg(t_data *data)
// {
// 	t_list	*env_list;
// 	char	*env_key_value;

// 	env_list = g_env;
// 	while ((char *)data->arg->content)
// 	{
// 		env_list = g_env;
// 		env_key_value = ft_strjoin()
// 		while (((t_env *)env_list->content)->)
// 		{

// 		}
// 	}
// 	return (0); // 끝까지 가면 0 리턴.
// }

// err부분은 나중에 처리해줘야함.
int	print_arg_err(t_data *data)
{
	ft_putstr_fd("env; ", 1);
	ft_putstr_fd((char *)data->arg->content, 1);
	ft_putstr_fd(" No such file or directory", 1);
}

// t_data *data가 굳이 필요할까는 짜면서 생각.
int env(t_data *data)
{
	t_list	*env_list;
	
	env_list = g_env;
	// 인자가 환경변수에 있는지 확인.
	if (data->arg->content)
	{
		print_arg_err(data);
		return (-1);
	}
	while (env_list)
	{
		if (((t_env *)env_list->content)->value)
		{
			ft_putstr_fd(((t_env *)env_list->content)->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(((t_env *)env_list->content)->value, 1);
		}
		env_list = env_list->next;
	}
}