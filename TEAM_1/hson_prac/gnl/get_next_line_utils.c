/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:40:39 by hson              #+#    #+#             */
/*   Updated: 2020/10/18 21:34:03 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

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
