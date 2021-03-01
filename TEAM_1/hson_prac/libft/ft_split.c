/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:31:34 by hson              #+#    #+#             */
/*   Updated: 2020/10/19 19:06:34 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_num_str(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s[i])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			n++;
			while (s[i] && s[i] == c)
				i++;
			continue;
		}
		i++;
	}
	if (s[i - 1] != c)
		n++;
	return (n);
}

static void		ft_get_substr(char **str, size_t *len, char c)
{
	size_t	i;

	*str += *len;
	*len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

static char		**ft_malloc_error(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	char	*sub_str;
	size_t	str_len;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	n = ft_get_num_str(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (n + 1))))
		return (0);
	i = 0;
	sub_str = (char *)s;
	str_len = 0;
	while (i < n)
	{
		ft_get_substr(&sub_str, &str_len, c);
		res[i] = (char *)malloc(sizeof(char) * str_len + 1);
		if (!res[i])
			return (ft_malloc_error(res));
		ft_strlcpy(res[i], sub_str, str_len + 1);
		i++;
	}
	res[i] = NULL;
	return (res);
}
