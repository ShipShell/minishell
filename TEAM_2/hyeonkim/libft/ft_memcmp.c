/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:49:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/09 13:56:50 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			idx;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n)
	{
		if (str1[idx] != str2[idx])
			return ((int)(str1[idx] - str2[idx]));
		idx++;
	}
	return (0);
}
