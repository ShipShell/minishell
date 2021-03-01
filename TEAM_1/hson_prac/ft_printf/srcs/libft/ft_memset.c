/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:09:43 by hson              #+#    #+#             */
/*   Updated: 2020/10/15 14:34:10 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	src;
	size_t			i;

	dest = (unsigned char *)ptr;
	src = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*dest++ = src;
		i++;
	}
	return (ptr);
}
