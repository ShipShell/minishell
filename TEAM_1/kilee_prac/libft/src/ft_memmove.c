/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:09:06 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/03 22:07:33 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned const char	*source;
	int					i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (source >= dest)
		while (++i < (int)len)
			dest[i] = source[i];
	else
	{
		while (len)
		{
			dest[len - 1] = source[len - 1];
			--len;
		}
	}
	return (dest);
}
