/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:20:34 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/09 12:49:57 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	char	*start;
	int		i;
	int		j;
	int		k;

	i = 0;
	if (*src == '\0')
		return (char *)(dst);
	while (i < (int)len && dst[i])
	{
		j = 0;
		start = (char *)(dst + i);
		k = i;
		while (*(dst + k) == *(src + j) && *(src + j) != '\0' && k < (int)len)
		{
			k++;
			j++;
		}
		if (*(src + j) == '\0')
			return ((char *)start);
		i++;
	}
	return (0);
}
