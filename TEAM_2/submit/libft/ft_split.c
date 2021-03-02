/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:44:03 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/13 00:10:32 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_num(char const *s, char c)
{
	int		idx;
	int		count;

	idx = 0;
	count = 0;
	while (s[idx] && s[idx] == c)
		idx++;
	while (s[idx])
	{
		while (s[idx] && s[idx] != c)
			idx++;
		while (s[idx] && s[idx] == c)
			idx++;
		count++;
	}
	return (count);
}

static char	**freedata(char **result, int idx)
{
	int		i;

	i = 0;
	while (i < idx)
	{
		free(result[idx]);
		idx++;
	}
	free(result);
	return (NULL);
}

static int	word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	int		num;
	int		len;
	int		idx;

	idx = 0;
	if (!s)
		return (NULL);
	num = word_num(s, c);
	if ((result = (char **)malloc(sizeof(char *) * (num + 1))) == 0)
		return (NULL);
	while (*s)
	{
		s += (*s == c ? 1 : 0);
		if (*s != c)
		{
			len = word_len(s, c);
			if (idx < num && !(result[idx] = ft_substr(s, 0, len)))
				return (freedata(result, idx));
			idx++;
			s += len;
		}
	}
	result[num] = 0;
	return (result);
}
