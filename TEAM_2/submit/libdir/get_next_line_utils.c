/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:43:40 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/12 16:13:27 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (ptr == 0)
		return (0);
	k = 0;
	while (k < i)
	{
		ptr[k] = s1[k];
		k++;
	}
	i = 0;
	while (i < j)
		ptr[k++] = s2[i++];
	ptr[k] = '\0';
	return (ptr);
}

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

char	*ft_strdup(const char *str)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i <= len)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
