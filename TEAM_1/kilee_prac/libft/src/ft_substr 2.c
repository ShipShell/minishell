/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:20:52 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/07 01:14:38 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup_static(const char *s1, size_t len)
{
	size_t		i;
	char		*dupl;

	dupl = (char *)malloc(sizeof(char) * len + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < len && s1[i])
	{
		dupl[i] = s1[i];
		++i;
	}
	dupl[i] = '\0';
	return (dupl);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	else if (ft_strlen(s) < start + 1)
	{
		sub = (char *)malloc(1);
		*sub = '\0';
		return (sub);
	}
	else
	{
		sub = ft_strndup_static(&s[start], len);
		return (sub);
	}
}
