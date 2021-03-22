/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:31:18 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 20:46:18 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	put_arg_to_std(t_cmd *cmd, int option, int i)
{
	if (cmd->token[i])
		ft_putstr_fd(cmd->token[i++], 1);
	while (cmd->token[i])
	{
		write(1, " ", 1);
		ft_putstr_fd(cmd->token[i++], 1);
	}
	if (!option)
		ft_putstr_fd("\n", 1);
	return (1);
}

int	check_option(t_cmd *cmd, int *i)
{
	char	*str;
	int		result;
	int		j;

	result = 0;
	while (cmd->token[*i])
	{
		str = cmd->token[*i];
		j = 1;
		if (!ft_strncmp(str, "-n", 2))
		{
			while (str[++j] == 'n')
				;
			if (str[j])
				return (result);
		}
		else
			return (result);
		result = 1;
		(*i)++;
	}
	return (result);
}

int	ft_echo(t_cmd *cmd)
{
	int	option;
	int	i;

	i = 1;
	option = 0;
	if (check_option(cmd, &i))
		option = 1;
	put_arg_to_std(cmd, option, i);
	g_exit_code = 0;
	return (1);
}
