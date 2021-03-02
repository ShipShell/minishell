/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xp_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:22:31 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/07 08:52:12 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long long n, int ud, t_key *key)
{
	char				c;
	unsigned long long	temp;
	char				*base;

	if (n < 0)
		n *= -1;
	if (ud == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	temp = n;
	c = base[temp % 16];
	if (n / 16 == 0)
		putfunc(c, key);
	else
	{
		print_hex(temp / 16, ud, key);
		putfunc(c, key);
	}
}

int		p_align_check(int count, t_key *key, unsigned long long result)
{
	int		i;
	char	c;

	c = ' ';
	i = -1;
	if (key->precision == 0 && result == 0)
		i--;
	while (++i < key->width - count)
		putfunc(c, key);
	return (0);
}

int		p_printer(t_key *key)
{
	unsigned long long	result;
	unsigned long long	temp;
	int					count;
	int					i;

	result = va_arg(key->ap, unsigned long long);
	count = 1;
	temp = result;
	while (temp /= 16)
		count++;
	count += 2;
	if (!(key->flag.minus))
		p_align_check(count, key, result);
	write(1, "0x", 2);
	key->result += 2;
	i = -1;
	while (++i < key->precision - count + 2)
		putfunc('0', key);
	if (!(result == 0 && key->precision == 0))
		print_hex(result, 1, key);
	if (key->flag.minus)
		p_align_check(count, key, result);
	return (0);
}

int		x_printer(t_key *key)
{
	unsigned long long int	result;
	unsigned long long int	temp;
	int						count;
	int						i;

	result = uhl_check(key, va_arg(key->ap, unsigned long long int));
	temp = result;
	count = 1;
	while (temp /= 16)
		count++;
	if (key->flag.zero && key->precision == -1 && key->flag.pound)
		x_util(key, 0, result);
	if (!(key->flag.minus))
		x_align_check(count, key, result);
	if (!(key->flag.zero && key->precision == -1) && key->flag.pound)
		x_util(key, 0, result);
	i = -1;
	while (++i < key->precision - count)
		putfunc('0', key);
	if (!(key->precision == 0 && result == 0))
		print_hex(result, 1, key);
	if (key->flag.minus)
		x_align_check(count, key, result);
	return (0);
}

int		ux_printer(t_key *key)
{
	unsigned long long int	result;
	unsigned long long int	temp;
	int						count;
	int						i;

	result = uhl_check(key, va_arg(key->ap, unsigned long long int));
	temp = result;
	count = 1;
	while (temp /= 16)
		count++;
	if (key->flag.zero && key->precision == -1 && key->flag.pound)
		x_util(key, 1, result);
	if (!(key->flag.minus))
		x_align_check(count, key, result);
	if (!(key->flag.zero && key->precision == -1) && key->flag.pound)
		x_util(key, 1, result);
	i = -1;
	while (++i < key->precision - count)
		putfunc('0', key);
	if (!(key->precision == 0 && result == 0))
		print_hex(result, 0, key);
	if (key->flag.minus)
		x_align_check(count, key, result);
	return (0);
}
