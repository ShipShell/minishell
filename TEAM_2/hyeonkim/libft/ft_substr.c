/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:07:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/12 21:36:49 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	src_len;
	size_t	idx;

	idx = 0;
	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (idx < len && start < src_len)
	{
		result[idx] = s[start];
		idx++;
		start++;
	}
	result[idx] = '\0';
	return (result);
}
