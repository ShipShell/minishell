/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:04:16 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/08 23:10:17 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_align_check(int count, t_key *key, union u_f result)
{
	int				i;
	char			c;
	long long int	front;

	if (key->flag.zero && !(key->flag.minus))
		c = '0';
	else
		c = ' ';
	i = -1;
	if (result.d < 0 || key->flag.plus || key->flag.space || result.s == 1)
		i++;
	front = (long long)result.d;
	i++;
	while (front /= 10)
		i++;
	if (key->precision == -1 || key->precision > 0 || key->flag.pound)
		i++;
	while (++i < key->width - count)
		putfunc(c, key);
	return (0);
}

int		bitcheck(union u_f result, t_key *key)
{
	if ((result.frac <<= (12 + key->precision)) == 0)
		return (1);
	else
		return (0);
}

int		bankround(int count, union u_f *result,
					long long int *front, t_key *key)
{
	int				sign;

	sign = 0;
	if ((*result).s != 0)
	{
		sign = 1;
		(*result).s = 0;
	}
	bankround_div(result, front, key, count);
	if ((*result).d >= 1.0)
		sign ? (*front)-- : (*front)++;
	return (0);
}

void	putdecimal(t_key *key, union u_f result, int count)
{
	int				i;
	long long int	front;
	long long int	dig;
	char			c;

	front = (long long)result.d;
	result.d = result.d - (long long)result.d;
	bankround(count, &result, &front, key);
	ft_putnbr_fd(front, key);
	if (key->precision == -1 || key->precision > 0 || key->flag.pound)
		putfunc('.', key);
	i = 0;
	dig = 1;
	while (i++ < count && i <= 18)
	{
		dig *= 10;
		c = (long long)(result.d * dig) % 10 + '0';
		putfunc(c, key);
	}
}

int		f_printer(t_key *key)
{
	union u_f	result;
	int			i;
	int			count;

	result.d = va_arg(key->ap, double);
	if (key->precision >= 0)
		count = key->precision;
	else
		count = 6;
	if (key->flag.zero)
		f_util(key, result.s);
	if (!(key->flag.minus))
		f_align_check(count, key, result);
	if (!(key->flag.zero))
		f_util(key, result.s);
	i = -1;
	while (++i < key->precision - count)
		putfunc('0', key);
	if (!(key->precision == 0 && result.d == 0) || key->flag.pound)
		putdecimal(key, result, count);
	else
		putfunc('0', key);
	if (key->flag.minus)
		f_align_check(count, key, result);
	return (0);
}
