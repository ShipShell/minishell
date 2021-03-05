/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:51:00 by kihoonlee         #+#    #+#             */
/*   Updated: 2021/03/05 14:45:45 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Split string to words
** Special case#1. ("hello","\0") > return "hello"
*/

static size_t	ft_word_size(char const *s, const char *set)
{
	size_t size;

	size = 0;
	while (*s && ft_strchr(set, *s++) == 0)
		size++;
	return (size);
}

static size_t	ft_word_amount(char const *s, const char *set)
{
	size_t amount;

	amount = 0;
	while (*s && ft_strchr(set, *s) != 0)
		s++;
	while (*s)
	{
		amount++;
		while (*s && ft_strchr(set, *s) == 0)
			s++;
		while (*s && ft_strchr(set, *s) != 0)
			s++;
	}
	return (amount);
}

void			ft_free_arr(char **s, int i)
{
	while (i)
		free(s[--i]);
	free(s);
}

char			**ft_split(char const *s, const char *set)
{
	char	**result;
	size_t	count;
	size_t	wordlen;
	size_t	i;

	count = ft_word_amount(s, set);
	if (!(result = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s && ft_strchr(set, *s) != 0)
			s++;
		wordlen = ft_word_size(s, set);
		if (!(result[i] = ft_strndup(s, wordlen)))
		{
			ft_free_arr(result, i - 1);
			return (0);
		}
		s += wordlen;
		i++;
	}
	result[count] = 0;
	return (result);
}
