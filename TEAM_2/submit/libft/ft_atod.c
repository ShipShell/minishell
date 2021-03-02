/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:18:07 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/15 10:45:11 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

double			ft_atod(const char *s)
{
	char		**data;
	double		result;
	int			sign;
	int			i[2];
	int			decimal_len;

	while (ft_isspace(*s) == 1)
		++s;
	sign = (*s == '-') ? -1 : 1;
	data = ft_split(s, '.');
	i[0] = ft_atoi(data[0]);
	if (data[1] == NULL)
		return ((double)i[0]);
	else
	{
		decimal_len = ft_strlen(data[1]);
		i[1] = ft_atoi(data[1]);
		if (sign == 1)
			result = (double)i[0] + (double)i[1] * pow(0.1, decimal_len);
		else
			result = (double)i[0] - (double)i[1] * pow(0.1, decimal_len);
	}
	return (result);
}
