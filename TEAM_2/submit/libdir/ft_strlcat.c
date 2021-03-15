/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:39:34 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/09 11:00:29 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	int	i;
	int	d_len;

	d_len = 0;
	while (d_len < (int)size + 1 && dst[d_len])
		d_len++;
	if ((int)size <= d_len)
		return (size + ft_strlen(src));
	i = 0;
	while (d_len + i + 1 < (int)size && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	if ((int)size < d_len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + d_len);
}
