/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:44:40 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/03 20:44:57 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	if (!src)
		return (0);
	while (src[len])
		++len;
	if (dstsize == 0 || !dst)
		return (len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len);
}
