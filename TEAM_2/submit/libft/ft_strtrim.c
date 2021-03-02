/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:51 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/12 21:11:47 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstart(const char *s1, const char *set)
{
	size_t i;

	i = -1;
	while (s1[++i])
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
	return (i);
}

static int	ft_getend(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1);
	while (--i >= 0)
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (end < start)
		return (ft_strdup(""));
	result = malloc(end - start + 2);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 2);
	return (result);
}
