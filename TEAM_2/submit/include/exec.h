#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <unistd.h>
# include "structures.h"
# include "libft.h"

int	ft_cd(t_cmd *cmd);
int	env(t_cmd *cmd);
int	ft_echo(t_cmd *cmd);
int	ft_pwd(t_cmd *cmd);
int	ft_unset(t_cmd *cmd);

#endif