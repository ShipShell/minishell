/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:13:00 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/08 23:53:06 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_key(t_key *key)
{
	key->flag.minus = 0;
	key->flag.plus = 0;
	key->flag.pound = 0;
	key->flag.space = 0;
	key->flag.zero = 0;
	key->width = -1;
	key->precision = -1;
	key->format = 0;
	key->percent = 0;
	key->flag.l = 0;
	key->flag.ll = 0;
	key->flag.h = 0;
	key->flag.hh = 0;
}

int		check_percent(char **str, t_key *key)
{
	int	check;

	check = 0;
	if (**str != '%')
	{
		putfunc(**str, key);
		(*str)++;
	}
	else
	{
		(*str)++;
		init_key(key);
		check_flag(str, key);
		check_width(str, key);
		check_precision(str, key);
		check_format(str, key);
		choose_printer(key);
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	char			*temp;
	t_key			*key;
	long long int	result;

	temp = (char *)str;
	if (!(key = (t_key *)malloc(sizeof(t_key) * 1)))
		return (-1);
	va_start(key->ap, str);
	key->result = 0;
	while (*temp)
		check_percent(&temp, key);
	result = key->result;
	free(key);
	return ((int)result);
}
