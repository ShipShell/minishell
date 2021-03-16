/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:14 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/16 15:09:37 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		call_no_home_err(void)
{
	ft_putstr_fd("shipshell: cd: HOME not set\n", 1);
	g_exit_code = 1;
	return (-1);
}

int		put_env_pwd(char *current_dir, t_list *pwd_lst)
{
	char	*pwd;
	int		len;
	int		i;

	len = ft_strlen(current_dir);
	pwd = (char *)malloc(sizeof(char) * (len + 1));
	if (pwd == 0)
		return (-1);
	i = -1;
	while (current_dir[++i])
		pwd[i] = current_dir[i];
	pwd[i] = 0;
	((t_env *)pwd_lst->content)->value = pwd;
	return (1);
}

char	*return_oldpwd()
{
	t_list	*env_list;

	env_list = g_env;
	while (env_list)
	{
		if (!ft_strcmp(((t_env *)env_list->content)->key, "OLDPWD"))
			return (((t_env *)env_list->content)->value);
		env_list = env_list->next;
	}
	return (0);
}
