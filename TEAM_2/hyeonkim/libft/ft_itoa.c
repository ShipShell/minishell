/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:02:58 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/10 14:57:21 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*fill_word(long n, int len, int sign)
{
	char	*word;

	if (sign == 1)
	{
		if ((word = (char *)malloc(sizeof(char) * len + 1)) == 0)
			return (NULL);
		word[len] = '\0';
	}
	else
	{
		if ((word = (char *)malloc(sizeof(char) * len + 2)) == 0)
			return (NULL);
		word[len + 1] = '\0';
	}
	if (sign == -1)
		len += 1;
	while (len)
	{
		word[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (sign == -1)
		word[0] = '-';
	return (word);
}

char		*ft_itoa(int n)
{
	long	tmp;
	long	div;
	int		len;
	int		sign;
	char	*result;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		sign *= -1;
		tmp = (long)n * (-1);
	}
	else
		tmp = (long)n;
	div = tmp;
	while (div >= 0)
	{
		div = div / 10;
		len++;
		if (div == 0)
			break ;
	}
	result = fill_word(tmp, len, sign);
	return (result);
}
