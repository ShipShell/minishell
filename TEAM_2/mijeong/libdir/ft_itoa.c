/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:53:18 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:18:47 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_itoa(char *ptr, int count, long long n)
{
	ptr[count--] = '\0';
	if (n == 0)
		ptr[count--] = '0';
	n = n < 0 ? -n : n;
	while (n)
	{
		ptr[count--] = n % 10 + '0';
		n /= 10;
	}
	if (count == 0)
		ptr[count] = '-';
}

char		*ft_itoa(int n)
{
	int			count;
	int			key;
	long long	temp;
	char		*ptr;

	key = n < 0 ? 1 : 0;
	count = 0;
	temp = n;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	if (temp == 0)
		count = 1;
	count += key;
	if (!(ptr = (char *)malloc(sizeof(char) * (count + 1))))
		return (0);
	put_itoa(ptr, count, temp);
	return (ptr);
}
