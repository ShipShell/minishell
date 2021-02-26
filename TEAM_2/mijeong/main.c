#include "exec.h"

int main(int ac, char **av, char **envv)
{
	t_data *data;
	t_list	*env;
	char	*buff;

	g_env = envv;
	data = (t_data *)malloc(sizeof(data) * 1);
	data->arg = ft_lstnew("../");
	env = g_env;
	while(env)
	{
		if (!ft_strcmp(((t_env *)env->content)->key, "PWD"))
		{
			printf("before %s = %s\n", ((t_env *)env->content)->key, ((t_env *)env->content)->value);
			getcwd(buff, 1000);
		}
		env = env->next;
	}
	env = g_env;
	ft_cd(data);
	while(env)
	{
		if (!ft_strcmp(((t_env *)env->content)->key, "PWD"))
		{
			printf("before %s = %s\n", ((t_env *)env->content)->key, ((t_env *)env->content)->value);
			getcwd(buff, 1000);
		}
		env = env->next;
	}
	return (0);
}