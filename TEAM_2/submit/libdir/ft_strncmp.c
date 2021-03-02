/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:02:27 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:22:32 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n && str1[i] && str2[i])
	{
		if (*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i))
			break ;
		i++;
	}
	if (i == (int)n)
		return (0);
	return (*(unsigned char *)(str1 + i) - *(unsigned char *)(str2 + i));
}
