/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 10:34:29 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/08 17:09:09 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t elt_count, size_t elt_size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(elt_size * elt_count);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < elt_count * elt_size)
		ptr[i++] = 0;
	return (void *)(ptr);
}
