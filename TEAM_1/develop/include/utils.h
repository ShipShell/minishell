#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "libft.h"
# include "parser.h"

t_cmd		*new_cmd(char *cmd_str);
void		add_back_new_cmd(t_cmd **cmds, t_cmd *new_cmd);
void		delete_data_in_cmd(void *data);
void		delete_one_cmd(t_cmd *cmd, void (*del)(void*));
void		delete_cmd_list(t_cmd **lst, void (*del)(void*));


t_env		*new_env(char *key, char *value);
void		add_back_new_env(t_env **envs, t_env *new_env);

#endif
