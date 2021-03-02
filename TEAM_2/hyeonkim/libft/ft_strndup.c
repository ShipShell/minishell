/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:43:42 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/15 08:40:37 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (s[idx] && idx < n)
	{
		result[idx] = s[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
