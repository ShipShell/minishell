#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"

t_list *g_env;

typedef struct	s_data
{
	char	*cmd;
	t_list	*arg;
	int		redirect_num;
	int		token;
}				t_data;

typedef struct	s_env
{
	char	*key;
	char	*value;
}				t_env;

int	ft_cd(t_data *data);

#endif