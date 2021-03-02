/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:49:29 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/10 14:51:14 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	idx;
	int				len;

	if (s && f)
	{
		idx = 0;
		len = ft_strlen(s);
		if (!(result = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[idx])
		{
			result[idx] = f(idx, s[idx]);
			idx++;
		}
		result[idx] = 0;
		return (result);
	}
	return (NULL);
}
