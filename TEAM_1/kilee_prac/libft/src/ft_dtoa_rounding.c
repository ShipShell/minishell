/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_rounding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:00:25 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/11/06 09:42:03 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_bank_check(t_dnum temp, unsigned long long round_devide)
{
	unsigned long long	front;

	front = temp.figure / round_devide;
	temp.num.num -= (long long)temp.num.num;
	if (temp.is_g == 1)
		temp.num.s_bit.frac_bit <<= temp.precision - temp.exponent - 1;
	else if (temp.specifier == 'f')
		temp.num.s_bit.frac_bit <<= temp.precision;
	else if (temp.specifier == 'e')
		temp.num.s_bit.frac_bit <<= temp.precision - temp.exponent;
	if (temp.num.s_bit.frac_bit != 0)
		return (1);
	else if (front & 1)
		return (1);
	return (0);
}

int		ft_up_check(t_dnum temp, long long devide)
{
	unsigned long long	round_devide;
	unsigned long long	exact_half;

	if (devide > 17 || devide < 1)
		return (0);
	round_devide = (long long)ft_pow(10, devide);
	exact_half = (long long)(5 * ft_pow(10, devide - 1));
	if (temp.figure % round_devide > exact_half)
		return (1);
	else if (temp.figure % round_devide < exact_half)
		return (0);
	else
		return (ft_bank_check(temp, round_devide));
}

int		ft_round_figure(t_dnum *dnum, int up, long long devide, int use_digit)
{
	devide = (long long)ft_pow(10, devide);
	dnum->figure = dnum->figure / devide;
	if (ft_intlen(dnum->figure) < ft_intlen(dnum->figure += up)
		|| (up == 1 && dnum->figure == 1 && use_digit == 0))
	{
		dnum->exponent += 1;
		if (dnum->is_g == 1 && dnum->exponent == 0 && dnum->precision == 0)
		{
			dnum->specifier = 'f';
			dnum->figure /= 10;
		}
		else if (dnum->is_g == 1 && dnum->exponent >= dnum->precision)
			dnum->specifier = 'e';
	}
	return (1);
}

int		ft_round_up(t_dnum *dnum)
{
	long long	devide;
	int			use_digit;
	int			up;
	t_dnum		temp;

	temp = *dnum;
	if (temp.num.s_bit.sign_bit == 1)
		temp.num.num *= -1;
	if (dnum->is_g == 1)
		use_digit = (dnum->precision == 0) ? 1 : dnum->precision;
	else if (dnum->specifier == 'f')
		use_digit = dnum->precision + dnum->exponent + 1;
	else
		use_digit = dnum->precision + 1;
	devide = 17 - use_digit;
	up = ft_up_check(temp, devide);
	if (use_digit >= 0 && use_digit < 17)
		ft_round_figure(dnum, up, devide, use_digit);
	else if (use_digit < 0)
		dnum->figure = 0;
	return (1);
}
