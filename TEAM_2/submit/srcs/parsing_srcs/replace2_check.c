/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace2_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:55:04 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 13:58:50 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_of_dollar(char *str, t_quoting quoting)
{
	int		len;

	len = 1;
	if (str[len] == '?')
		++len;
	else
	{
		while (str[len] && (ft_isalpha(str[len]) || str[len] == '_'))
			++len;
	}
	return (len);
}

static int	len_not_to_replace(char *str, t_quoting quoting)
{
	int		len;

	len = 1;
	while (str[len]
		&& check_whether_replace(str[len], quoting) == NOT_TO_REPLACE)
		++len;
	return (len);
}

int			check_replace_len(char *str, t_quoting quoting)
{
	int		len;
	int		tmp;
	int		replace_check;

	replace_check = check_whether_replace(*str, quoting);
	if (replace_check == DOLLAR_ON)
		len = len_of_dollar(str, quoting);
	else if (replace_check == NOT_TO_REPLACE)
		len = len_not_to_replace(str, quoting);
	else
		len = 1;
	return (len);
}
