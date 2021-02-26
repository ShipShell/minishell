/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:18:10 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/11/05 19:32:27 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_len(unsigned long long n)
{
	int		len;

	len = 0;
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

char			*ft_ultoa(unsigned long long n)
{
	char		*ltoa;
	int			len;

	if (n == 0)
	{
		ltoa = zero_toa();
		return (ltoa);
	}
	len = ft_num_len(n);
	if (!(ltoa = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ltoa[len--] = '\0';
	while (n)
	{
		ltoa[len--] = n % 10 + '0';
		n /= 10;
	}
	return (ltoa);
}
