/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:55:27 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/09 15:25:14 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			idx;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	idx = 0;
	while ((ss1[idx] || ss2[idx]) && idx < n)
	{
		if (ss1[idx] != ss2[idx])
			return (ss1[idx] - ss2[idx]);
		idx++;
	}
	return (0);
}
