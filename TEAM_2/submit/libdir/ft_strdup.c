/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 10:41:15 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/05 21:37:10 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
	{
		free(result);
		return (0);
	}
	i = 0;
	while (i <= len)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
