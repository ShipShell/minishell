/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:14:39 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:20:15 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	int				i;
	unsigned char	temp;

	temp = (unsigned char)value;
	i = 0;
	while (i < (int)num)
	{
		*((unsigned char *)(ptr + i)) = temp;
		i++;
	}
	return (ptr);
}
