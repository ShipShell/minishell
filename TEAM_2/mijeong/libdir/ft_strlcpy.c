/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:32:39 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:22:04 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	count;
	int	i;

	if (dst == 0 || src == 0)
		return (0);
	count = 0;
	i = 0;
	while (src[count] != '\0')
		count++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (int)(size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}
