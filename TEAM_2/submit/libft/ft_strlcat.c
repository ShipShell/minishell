/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:16:03 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/07 16:19:47 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	d_idx;
	size_t	s_idx;

	d_idx = ft_strlen(dest);
	s_idx = 0;
	if (size <= d_idx)
		return (ft_strlen(src) + size);
	while (src[s_idx] && d_idx + s_idx < (size - 1))
	{
		dest[d_idx + s_idx] = src[s_idx];
		s_idx++;
	}
	dest[d_idx + s_idx] = '\0';
	return (ft_strlen(src) + d_idx);
}
