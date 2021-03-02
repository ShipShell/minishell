/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:32:00 by mijeong           #+#    #+#             */
/*   Updated: 2020/09/29 13:37:37 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	int	i;

	i = 0;
	while (i < (int)num)
	{
		if (*(unsigned char *)(ptr1 + i) != *(unsigned char *)(ptr2 + i))
			break ;
		i++;
	}
	if (i == (int)num)
		return (0);
	return (*(unsigned char *)(ptr1 + i) - *(unsigned char *)(ptr2 + i));
}
