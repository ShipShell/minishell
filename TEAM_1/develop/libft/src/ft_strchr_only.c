/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:41:03 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/28 17:56:17 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_only(const char *s, int c)
{
	if (c == 0)
		return ((char *)s);
	while (*s)
	{
		if (*s != c)
			return (NULL);
		++s;
	}
	return ((char *)s);
}
