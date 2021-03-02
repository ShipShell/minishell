/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:18:07 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/02 16:04:47 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *s)
{
	int			idx;
	int			sign;
	int			cnt;
	long long	result;

	cnt = 0;
	idx = 0;
	sign = 1;
	result = 0;
	while (s[idx] && (ft_isspace(s[idx]) == 1))
		idx++;
	s[idx] == '-' ? sign *= -1 : 0;
	if (s[idx] == '-' || s[idx] == '+')
		idx++;
	while (s[idx] && s[idx] >= '0' && s[idx] <= '9')
	{
		result = result * 10 + (s[idx] - '0') * sign;
		idx++;
		cnt++;
	}
	if (cnt > 20 && sign == 1)
		return (-1);
	else if (cnt > 20 && sign == -1)
		return (0);
	return (result);
}
