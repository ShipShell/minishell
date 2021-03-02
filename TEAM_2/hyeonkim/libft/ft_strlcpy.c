/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:37:31 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/12 20:00:51 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	src_len;

	idx = 0;
	src_len = 0;
	if (!dest && !src)
		return (0);
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[idx] && idx < size - 1)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (src_len);
}
