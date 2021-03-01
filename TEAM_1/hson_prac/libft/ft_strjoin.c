/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:02:19 by hson              #+#    #+#             */
/*   Updated: 2020/10/18 21:28:19 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		len1;
	size_t		len2;
	size_t		i;

	if (!s1 || !s2)
	{
		if (!s1 && s2)
			return (ft_strdup(s2));
		if (s1 && !s2)
			return (ft_strdup(s1));
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < len1)
		res[i++] = *s1++;
	while (i < len1 + len2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
