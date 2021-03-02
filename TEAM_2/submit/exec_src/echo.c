#include "exec.h"

int	put_arg_to_std(t_data *data, int option)
{
	t_list	*arg_list;

	arg_list = data->arg;
	if ((char *)arg_list->content)
	{
		ft_putstr_fd((char *)arg_list->content, 1);
		arg_list = arg_list->next;
	}
	arg_list = arg_list->next;
	while ((char *)data->arg->content)
	{
		write(1, " ", 1);
		ft_putstr_fd((char *)arg_list->content, 1);
		arg_list = arg_list->next;
	}
	if (option)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	ft_echo(t_data *data)
{
	int	option;

	option = 0;
	if (!ft_strcmp((char *)data->arg->content, "-n"))
		option = 1;
	put_arg_to_std(data, option);
	
	return (0);
}