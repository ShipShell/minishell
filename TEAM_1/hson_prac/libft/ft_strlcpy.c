/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:49:08 by hson              #+#    #+#             */
/*   Updated: 2020/10/15 15:11:50 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		src_len;

	if (!dest && !src)
		return (0);
	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!dstsize)
		return (src_len);
	while (src[i] && i < dstsize - 1 && dstsize > 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
