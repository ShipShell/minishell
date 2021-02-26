/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:18:10 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/29 09:30:16 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_num_len(long long n)
{
	int			len;

	len = 0;
	if (n < 0)
	{
		++len;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static char		*zero_toa(void)
{
	char *zero;

	if (!(zero = (char *)malloc(2)))
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

char			*ft_ltoa(long long n)
{
	char		*ltoa;
	long long	num;
	int			len;

	if (n == 0)
	{
		ltoa = zero_toa();
		return (ltoa);
	}
	num = n;
	len = ft_num_len(n);
	if (!(ltoa = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (num < 0)
		num *= -1;
	ltoa[len--] = '\0';
	while (num)
	{
		ltoa[len--] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		ltoa[len] = '-';
	return (ltoa);
}
