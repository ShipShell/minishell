/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:18:15 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/07 00:27:07 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end != 0 && ft_strchr(set, s1[end]))
		end--;
	if (end - start <= 0)
		ptr = (char *)malloc(sizeof(char) * 1);
	else
		ptr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (ptr == 0)
		return (0);
	i = -1;
	while (++i < end - start + 1)
		ptr[i] = s1[start + i];
	ptr[i] = '\0';
	return (ptr);
}
