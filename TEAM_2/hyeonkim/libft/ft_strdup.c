/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:14:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/09 15:20:19 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*result;
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (s[idx])
	{
		result[idx] = s[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
