/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:35:51 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/09 13:39:08 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	while (idx >= 0)
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx--;
	}
	return (NULL);
}
