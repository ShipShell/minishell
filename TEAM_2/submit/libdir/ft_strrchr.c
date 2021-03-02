/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:58:42 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:25:46 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int chr)
{
	char	*temp_ptr;
	int		temp_len;
	int		i;

	i = 0;
	temp_ptr = 0;
	temp_len = ft_strlen(str);
	while (i <= temp_len)
	{
		if (str[i] == (char)chr)
			temp_ptr = str + i;
		i++;
	}
	return (temp_ptr);
}
