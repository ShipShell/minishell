/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:25:10 by hson              #+#    #+#             */
/*   Updated: 2020/11/17 14:09:12 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(long long n)
{
	return ((n < 0) ? -n : n);
}

char	*ft_itoa(long long n)
{
	long long	n_;
	int			len;
	char		*res;

	n_ = n;
	len = ft_nbrlen(n);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (n_ < 0)
		res[0] = '-';
	return (res);
}
