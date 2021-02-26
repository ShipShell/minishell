/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:58:11 by hson              #+#    #+#             */
/*   Updated: 2020/10/14 19:46:16 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*dest2;
	size_t			i;

	if (!s1 && !s2)
		return (0);
	dest1 = (unsigned char *)s1;
	dest2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (dest1[i] != dest2[i])
			return (dest1[i] - dest2[i]);
		i++;
	}
	return (0);
}
