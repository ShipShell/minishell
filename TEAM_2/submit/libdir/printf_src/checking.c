/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:40:44 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/08 23:56:18 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char **str, t_key *key)
{
	while (**str == 'l' || **str == 'h')
	{
		if (**str == 'l')
		{
			key->flag.ll = key->flag.l ? 1 : key->flag.ll;
			key->flag.l = !key->flag.l ? 1 : key->flag.l;
		}
		else if (**str == 'h')
		{
			key->flag.hh = key->flag.h ? 1 : key->flag.hh;
			key->flag.h = !key->flag.h ? 1 : key->flag.h;
		}
		(*str)++;
	}
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd'
		|| **str == 'i' || **str == 'u' || **str == 'x' || **str == 'X'
		|| **str == '%' || **str == 'f' || **str == 'n')
	{
		key->format = **str;
		(*str)++;
	}
	return (1);
}

int	check_astro(char **str, t_key *key, int *i, int pw_switch)
{
	int	temp;

	if (**str == '*')
	{
		(*str)++;
		temp = va_arg(key->ap, int);
		if (temp < 0)
		{
			if (pw_switch == 1)
				key->flag.minus = 1;
			else
				return (1);
			temp *= -1;
		}
		key->width = pw_switch == 1 ? temp : key->width;
		key->precision = pw_switch != 1 ? temp : key->precision;
		return (1);
	}
	else
	{
		while ((*str)[*i] >= '0' && (*str)[*i] <= '9')
			(*i)++;
	}
	return (0);
}

int	check_precision(char **str, t_key *key)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = -1;
	if (*str[i] == '.')
	{
		(*str)++;
		if (check_astro(str, key, &i, 0))
			return (1);
		if (!(ptr = (char *)malloc(sizeof(char) * (i + 1))))
			return (-1);
		while (++j < i)
			ptr[j] = (*str)[j];
		ptr[j] = '\0';
		key->precision = ft_atoi(ptr);
		*str = (*str) + i;
		free(ptr);
		return (1);
	}
	else
		return (0);
}

int	check_width(char **str, t_key *key)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = -1;
	if (check_astro(str, key, &i, 1))
		return (1);
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
		i++;
	if (!(ptr = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	while (++j < i)
		ptr[j] = (*str)[j];
	ptr[j] = '\0';
	key->width = ft_atoi(ptr);
	*str = (*str) + i;
	free(ptr);
	return (1);
}

int	check_flag(char **str, t_key *key)
{
	while (**str)
	{
		if (**str == '-')
			key->flag.minus = 1;
		else if (**str == '0')
			key->flag.zero = 1;
		else if (**str == '#')
			key->flag.pound = 1;
		else if (**str == '+')
			key->flag.plus = 1;
		else if (**str == ' ')
			key->flag.space = 1;
		else
			return (0);
		(*str)++;
	}
	return (1);
}
