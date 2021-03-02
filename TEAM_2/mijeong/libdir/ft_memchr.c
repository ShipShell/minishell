/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:20:35 by mijeong           #+#    #+#             */
/*   Updated: 2020/09/29 12:31:32 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num)
{
	int	i;
	int	temp;

	i = 0;
	temp = (int)num;
	while (i < temp)
	{
		if (*(char *)(ptr + i) == (char)value)
			return (ptr + i);
		i++;
	}
	return (0);
}
