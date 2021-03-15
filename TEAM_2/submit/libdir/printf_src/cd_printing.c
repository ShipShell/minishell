/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:40:39 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/09 00:00:38 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_align_check(t_key *key)
{
	int		i;
	char	c;

	i = 0;
	if (key->flag.zero)
		c = '0';
	else
		c = ' ';
	while (++i < key->width)
		putfunc(c, key);
	return (0);
}

int	c_printer(t_key *key)
{
	wint_t	result;

	if (key->flag.l)
		result = va_arg(key->ap, wint_t);
	else
		result = va_arg(key->ap, int);
	if (!(key->flag.minus))
		c_align_check(key);
	putfunc(result, key);
	if (key->flag.minus)
		c_align_check(key);
	return (0);
}

int	align_check(int count, t_key *key, long long int result)
{
	int		i;
	char	c;

	if (key->flag.zero && key->precision == -1 && !(key->flag.minus))
		c = '0';
	else
		c = ' ';
	if (count <= key->precision)
		count = key->precision;
	i = -1;
	if (result < 0 || key->flag.plus || key->flag.space)
		i++;
	if (key->flag.pound && result != 0)
		i += 2;
	while (++i < key->width - count)
		putfunc(c, key);
	if (result == 0 && key->precision == 0 &&
		(key->width > 1 || (key->width == 1 && (!key->flag.plus
		&& !key->flag.space))))
		putfunc(' ', key);
	return (0);
}

int	d_printer(t_key *key)
{
	long long int	result;
	long long int	i;
	int				count;

	result = hl_check(key, va_arg(key->ap, long long int));
	i = result;
	count = 1;
	while (i /= 10)
		count++;
	if (key->flag.zero && key->precision == -1)
		d_util(key, result);
	if (!(key->flag.minus))
		align_check(count, key, result);
	if (!(key->flag.zero && key->precision == -1))
		d_util(key, result);
	i = -1;
	while (++i < key->precision - count)
		putfunc('0', key);
	if (!(key->precision == 0 && result == 0))
		ft_putnbr_fd(result, key);
	if (key->flag.minus)
		align_check(count, key, result);
	return (0);
}

int	choose_printer(t_key *key)
{
	if (key->format == 'd')
		d_printer(key);
	else if (key->format == 'i')
		d_printer(key);
	else if (key->format == 'c')
		c_printer(key);
	else if (key->format == 's' && key->flag.l)
		ls_printer(key);
	else if (key->format == 's' && !(key->flag.l))
		s_printer(key);
	else if (key->format == 'u')
		u_printer(key);
	else if (key->format == 'p')
		p_printer(key);
	else if (key->format == 'x')
		x_printer(key);
	else if (key->format == 'X')
		ux_printer(key);
	else if (key->format == '%')
		per_printer(key);
	else if (key->format == 'f')
		f_printer(key);
	else if (key->format == 'n')
		n_printer(key);
	return (1);
}
