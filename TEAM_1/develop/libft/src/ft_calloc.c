/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:32:02 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/03 20:32:59 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	size_t	i;

	arr = (char *)malloc(size * count);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		arr[i] = 0;
		++i;
	}
	return ((void *)arr);
}
