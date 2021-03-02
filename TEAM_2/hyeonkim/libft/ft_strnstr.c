/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:00:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/13 18:32:21 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		str_check(const char *big, const char *little)
{
	size_t	l_idx;
	size_t	b_idx;

	l_idx = 0;
	b_idx = 0;
	while (little[l_idx])
	{
		if (little[l_idx] == big[b_idx])
		{
			l_idx++;
			b_idx++;
		}
		else
			return (0);
	}
	return (1);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t idx;
	size_t lit_len;

	idx = 0;
	lit_len = 0;
	if (*little == 0)
		return ((char *)big);
	while (little[lit_len])
		lit_len++;
	while (*big != 0 && idx + lit_len <= len)
	{
		if (*big == *little)
		{
			if (str_check(big, little) == 1)
				return ((char *)big);
		}
		++big;
		idx++;
	}
	return (NULL);
}
