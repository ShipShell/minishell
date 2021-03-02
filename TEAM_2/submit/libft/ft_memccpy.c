/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:36:15 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/09 13:57:33 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*src_str;
	unsigned char	*dest_str;
	size_t			idx;

	idx = 0;
	src_str = (unsigned char *)src;
	dest_str = (unsigned char *)dest;
	while (idx < n)
	{
		dest_str[idx] = src_str[idx];
		if (src_str[idx] == (unsigned char)c)
			return ((void *)(dest + idx + 1));
		idx++;
	}
	return (NULL);
}
