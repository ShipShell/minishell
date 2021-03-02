#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "libft.h"
# include "parser.h"

t_cmd		*new_cmd(char **new_cmd);
void		add_back_new_cmd(t_cmd **cmds, t_cmd *new_cmd);
t_env		*new_env(char **key_value);
void		add_back_new_env(t_env **envs, t_env *new_env);

#endif
