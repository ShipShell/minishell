/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:30:36 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/08 17:11:27 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	int	i;

	if (destination == 0 && source == 0)
		return (0);
	i = 0;
	while (i < (int)num)
	{
		*(char *)(destination + i) = *(char *)(source + i);
		i++;
	}
	return (destination);
}
