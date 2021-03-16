/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:41:17 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/05 19:19:49 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	c_trans;
	size_t			i;

	if (dst == src || n == 0)
		return (NULL);
	c_trans = (unsigned char)c;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if (dest[i] == c_trans)
			return (dest + i + 1);
		++i;
	}
	return (NULL);
}
