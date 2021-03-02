/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:36:13 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/09 15:23:14 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	idx;

	idx = 0;
	if (dest == 0 && src == 0)
		return (0);
	if (dest <= src)
	{
		while (idx < num)
		{
			((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
			idx++;
		}
	}
	else
	{
		while (num)
		{
			((unsigned char *)dest)[num - 1] = ((unsigned char *)src)[num - 1];
			num--;
		}
	}
	return (dest);
}
