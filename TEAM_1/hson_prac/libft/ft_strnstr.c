/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 23:47:50 by hson              #+#    #+#             */
/*   Updated: 2020/10/21 14:46:25 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	str_len;
	size_t	fnd_len;

	if (*to_find == '\0')
		return ((char *)str);
	str_len = ft_strlen(str);
	fnd_len = ft_strlen(to_find);
	if (str_len < fnd_len || fnd_len > len)
		return (0);
	while (*str && len >= fnd_len)
	{
		if (ft_strncmp(str, to_find, fnd_len) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (0);
}
