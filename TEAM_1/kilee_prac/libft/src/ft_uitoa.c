/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:18:10 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/24 23:03:15 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_num_len(unsigned int n)
{
	int			len;

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

char			*ft_uitoa(unsigned int n)
{
	char		*itoa;
	int			len;

	if (n == 0)
	{
		itoa = zero_toa();
		return (itoa);
	}
	len = ft_num_len(n);
	if (!(itoa = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	itoa[len--] = '\0';
	while (n)
	{
		itoa[len--] = n % 10 + '0';
		n /= 10;
	}
	return (itoa);
}
