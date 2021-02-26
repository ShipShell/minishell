/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:46:42 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/14 09:10:48 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If src in target before target_len, return start of that point
** Special case#1: ("abcabcdef","abcd",30) -> return &target[3] 'a'
*/

char	*ft_strnstr(const char *target, const char *src, size_t target_len)
{
	size_t	src_len;

	if (*src == '\0')
		return ((char *)target);
	src_len = ft_strlen(src);
	while (*target && target_len-- >= src_len)
	{
		if (*target == *src && ft_strncmp(target, src, src_len) == 0)
			return ((char *)target);
		target++;
	}
	return (NULL);
}
