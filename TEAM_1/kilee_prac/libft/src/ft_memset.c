/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:24:42 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/03 22:04:14 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *b_mem;
	unsigned char c_mem;
	unsigned long i;

	b_mem = (unsigned char *)b;
	c_mem = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		b_mem[i] = c_mem;
		++i;
	}
	return (b_mem);
}
