/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:05:04 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 13:05:13 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_del_one(void *target)
{
	free(target);
}

void	delete_redir_in_cmd(t_redir *redir)
{
	if (redir == NULL)
		return ;
	ft_lstclear(&redir->file, lst_del_one);
	free(redir);
}

t_env	*new_env(char *key, char *value)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env) * 1)))
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
		new->val = ft_strdup(value);
	else
		new->val = NULL;
	new->next = NULL;
	return (new);
}

void	add_back_new_env(t_env **envs, t_env *new_env)
{
	t_env	*cur;

	if (*envs == NULL)
	{
		*envs = new_env;
		return ;
	}
	cur = *envs;
	while (cur->next)
		cur = cur->next;
	cur->next = new_env;
}

t_redir	*init_redir(void)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (redir == NULL)
		exit(1);
	redir->fd = 0;
	redir->tmp_std = 0;
	redir->is_double = FALSE;
	redir->file = NULL;
	return (redir);
}
