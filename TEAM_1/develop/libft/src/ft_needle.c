/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:51:17 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 19:29:06 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_needle(const char *s1, const char *needle, int n_point)
{
	char	*dst;
	int		i;
	int		needle_len;

	needle_len = ft_strlen(needle);
	if (!(dst = (char *)malloc(ft_strlen(s1) + needle_len + 1)))
		return (NULL);
	i = 0;
	while (i < n_point)
		dst[i++] = *(s1++);
	ft_strlcpy(&dst[i], needle, needle_len + 1);
	i += needle_len;
	while (*s1)
		dst[i++] = *(s1++);
	dst[i] = '\0';
	return (dst);
}
