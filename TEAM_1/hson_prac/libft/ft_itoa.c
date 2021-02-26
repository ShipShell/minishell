/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:25:10 by hson              #+#    #+#             */
/*   Updated: 2020/10/16 22:05:23 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(long n)
{
	return ((n < 0) ? -n : n);
}

int		ft_nbrlen(int n)
{
	int i;

	i = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		n_;
	int		len;
	char	*res;

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
