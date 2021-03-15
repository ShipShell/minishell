/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:05:16 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/08 14:53:42 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	int	i;
	int	temp;

	if (destination == 0 && source == 0)
		return (destination);
	temp = (int)num;
	i = 0;
	if (destination < source)
	{
		while (i < temp)
		{
			*(char *)(destination + i) = *(char *)(source + i);
			i++;
		}
		return (destination);
	}
	else
	{
		while (0 <= --temp)
		{
			*(char *)(destination + temp) = *(char *)(source + temp);
		}
	}
	return (destination);
}
