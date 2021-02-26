/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:18:10 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/29 09:27:31 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_num_len(int n)
{
	long long	num;
	int			len;

	num = n;
	len = 0;
	if (num < 0)
	{
		++len;
		num *= -1;
	}
	while (num)
	{
		num /= 10;
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

char			*ft_itoa(int n)
{
	char		*itoa;
	long long	num;
	int			len;

	if (n == 0)
	{
		itoa = zero_toa();
		return (itoa);
	}
	num = n;
	len = ft_num_len(n);
	if (!(itoa = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (num < 0)
		num *= -1;
	itoa[len--] = '\0';
	while (num)
	{
		itoa[len--] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		itoa[len] = '-';
	return (itoa);
}
