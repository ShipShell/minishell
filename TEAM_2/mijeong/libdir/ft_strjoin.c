/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:29:58 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:21:44 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (ptr == 0)
		return (0);
	k = 0;
	while (k < i)
	{
		ptr[k] = s1[k];
		k++;
	}
	i = 0;
	while (i < j)
		ptr[k++] = s2[i++];
	ptr[k] = '\0';
	return (ptr);
}
