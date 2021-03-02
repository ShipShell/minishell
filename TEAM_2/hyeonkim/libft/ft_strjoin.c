/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:20:55 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/12 20:04:08 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx1;
	size_t	idx2;
	size_t	len;
	char	*result;

	idx1 = 0;
	idx2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (s1[idx1])
	{
		result[idx1] = s1[idx1];
		idx1++;
	}
	while (s2[idx2])
	{
		result[idx1 + idx2] = s2[idx2];
		idx2++;
	}
	result[idx1 + idx2] = '\0';
	return (result);
}
