/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:52:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/05 21:06:17 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_str;
	unsigned char	*dest_str;

	if (src == 0 && dest == 0)
		return (0);
	src_str = (unsigned char *)src;
	dest_str = (unsigned char *)dest;
	while (n--)
		*(dest_str++) = *(src_str++);
	return (dest);
}
