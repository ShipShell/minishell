#include "minishell.h"

int		chk_arg_cnt_env()
{
	t_env *env;
	int i;

	env = g_env;
	i = 0;
	while (env)
	{
		if (env->key)
			i++;
		env = env->next;
	}
	return (i);
}

void	ft_sort_env(t_env **sort_env, int size)
{
	int	i;
	int	j;
	t_env	*tmp;

	i = 0;
	j = 0;	
	while (j++ < size)
	{
		i = 0;
		while (++i < size)
		{
			if(ft_strcmp(sort_env[i - 1]->key, sort_env[i]->key) > 0)
			{
				tmp = sort_env[i - 1];
				sort_env[i - 1] = sort_env[i];
				sort_env[i] = tmp;
			}
		}
	}
}

void	print_export_sub(t_env **sort_env)
{
	int	i;

	i = 0;
	while (sort_env[i])
	{
		ft_putstr(sort_env[i]->key);
		if (sort_env[i]->val)
		{
			write(1, "=\"", 2);
			ft_putstr(sort_env[i]->val);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_export()
{
	t_env 	*env;
	t_env	**sort_env;
	int		size;
	int		i;

	env = g_env;
	size = chk_arg_cnt_env();
	sort_env = (t_env **)malloc(sizeof(t_env *) * (size + 1));
	i = -1;
	while (++i < size)
	{
		sort_env[i] = env;
		env = env->next;
	}
	sort_env[i] = 0;
	ft_sort_env(sort_env, size);
	print_export_sub(sort_env);
}

void	put_env(char *str)
{
	size_t	ret;
	char	*key;
	char	*val;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break;
		i++;
	}
	//printf("i = %d\n", i);
	key = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(key, str, i + 1);
	j = 0;
	if (str[i])
	{
		while (j++ < i + 1)
			str++;
		val = str;
	}
	else
		val = 0;
	//printf("%s : %s\n", key, val);
	lst_change_add_env(key, val);
}

int		exec_export(t_cmd *cmd)
{
	t_env	*env;
	int	i;

	env = g_env;
	i = 1;
	if (!cmd->command[1])
		print_export();
	while (cmd->command[i])
	{
		if (ft_isdigit(cmd->command[i][0]) || cmd->command[i][0] == '=')
			return (not_valid_idt(cmd, cmd->command[i], 1));
		put_env(cmd->command[i]);
		i++;
	}
	return (0);
}