/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:43:35 by kilee             #+#    #+#             */
/*   Updated: 2020/10/20 08:43:36 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t len)
{
	size_t		i;
	char		*dupl;

	dupl = (char *)malloc(sizeof(char) * len + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < len && s1[i])
	{
		dupl[i] = s1[i];
		++i;
	}
	dupl[i] = '\0';
	return (dupl);
}
