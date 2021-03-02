/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:12:42 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:21:33 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	int	i;
	int	str_len;

	str_len = ft_strlen(str);
	i = 0;
	while (i <= str_len)
	{
		if (str[i] == (char)chr)
			return (char *)(str + i);
		i++;
	}
	return (0);
}
