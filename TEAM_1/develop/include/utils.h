/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:23:07 by hson              #+#    #+#             */
/*   Updated: 2021/03/16 13:16:20 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "libft.h"
# include "parser.h"

/*
** utils.c
*/
t_cmd		*new_cmd(char *cmd_str);
void		add_back_new_cmd(t_cmd **cmds, t_cmd *new_cmd);
void		delete_data_in_cmd(void *data);
void		delete_cmd_list(t_cmd **lst, void (*del)(void*));
void		delete_one_cmd(t_cmd *cmd, void (*del)(void*));

/*
** utils2.c
*/
void		lst_del_one(void *target);
void		delete_redir_in_cmd(t_redir *redir);
t_env		*new_env(char *key, char *value);
void		add_back_new_env(t_env **envs, t_env *new_env);
t_redir		*init_redir(void);

#endif
