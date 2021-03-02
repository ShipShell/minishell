/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:29:22 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/02 14:04:07 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**dinit(char const *s, char c, int *j)
{
	int		i;
	int		key;
	char	**ptr;

	key = 0;
	*j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && key == 0)
		{
			key = 1;
			(*j)++;
		}
		else if (s[i] == c)
			key = 0;
		i++;
	}
	ptr = (char **)malloc(sizeof(char *) * (*j + 1));
	if (ptr == 0)
		return (0);
	return (ptr);
}

static char	*putresult(char const *s, int start, int i)
{
	char	*ptr;
	int		j;

	j = 0;
	ptr = (char *)malloc(sizeof(char) * (i - start + 1));
	if (ptr == 0)
	{
		free(ptr);
		return (0);
	}
	while (start < i)
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		start;
	char	**result;

	i = 0;
	k = 0;
	if (s == 0)
		return (0);
	result = dinit(s, c, &j);
	if (result == 0)
		return (0);
	while (k < j)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[k++] = putresult(s, start, i);
		i++;
	}
	result[k] = 0;
	return (result);
}
