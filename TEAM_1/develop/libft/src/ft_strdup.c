/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:41:17 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/03 20:41:18 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dupl;

	len = 0;
	while (s1[len])
		++len;
	dupl = (char *)malloc(sizeof(char) * len + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dupl[i] = s1[i];
		++i;
	}
	dupl[i] = '\0';
	return (dupl);
}
