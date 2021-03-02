/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:40:07 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/12 20:22:54 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (ptr);
	while (i < (unsigned int)len && start + i < s_len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
