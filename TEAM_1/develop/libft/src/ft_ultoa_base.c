/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:18:10 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/11/05 19:28:02 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long long value, char *base)
{
	int					count;
	unsigned long long	tmp;
	char				*res;
	unsigned long long	base_length;

	base_length = ft_strlen(base);
	count = 1;
	tmp = value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = value;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}
