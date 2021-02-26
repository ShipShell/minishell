/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:20:25 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/03 21:20:26 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	while (end > 0 && ft_strchr(set, s1[end]))
		--end;
	if (start > end)
	{
		trim = (char *)malloc(1);
		*trim = '\0';
		return (trim);
	}
	if (!(trim = (char *)malloc(end - start + 2)))
		return (NULL);
	ft_strlcpy(trim, &s1[start], end - start + 2);
	return (trim);
}
