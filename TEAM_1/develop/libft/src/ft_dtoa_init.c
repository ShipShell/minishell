/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:00:25 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/11/06 19:38:17 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_nan_check(t_dnum *dnum)
{
	if (dnum->num.s_bit.exp_bit == 2047 && dnum->num.s_bit.frac_bit == 0)
		dnum->num_str = ft_strdup("inf");
	else if (dnum->num.s_bit.exp_bit == 2047 && dnum->num.s_bit.frac_bit != 0)
		dnum->num_str = ft_strdup("nan");
	else
		return (0);
	return (1);
}

int		ft_dtoa_get_exponent(t_dnum *dnum)
{
	double	num;
	int		exp;

	num = dnum->num.num;
	if (num < 0)
		num *= -1;
	exp = 0;
	if (num < 1 && num > 0)
	{
		while (num < 1)
		{
			++exp;
			num *= 10;
		}
		if (num > 9.999999999999999)
			--exp;
		dnum->exponent = -exp;
	}
	else
		dnum->exponent = ft_intlen(num) - 1;
	return (1);
}

int		ft_dtoa_get_figure(t_dnum *dnum)
{
	unsigned long long	jungsoo;
	unsigned long long	sosoo;
	double				num;
	double				double_to_long;

	num = dnum->num.num;
	if (num < 0)
		num *= -1;
	double_to_long = ft_pow(10.0, 16 - dnum->exponent);
	jungsoo = (long long)num * double_to_long;
	num -= (long long)num;
	sosoo = num * double_to_long;
	dnum->figure = jungsoo + sosoo;
	if (ft_intlen(dnum->figure) < 17)
		dnum->figure += 10;
	return (1);
}

int		ft_spec_g_check(t_dnum *dnum)
{
	if (dnum->specifier == 'g')
	{
		if (dnum->exponent < -4 || (dnum->exponent >= dnum->precision))
		{
			if (dnum->exponent == 0 && dnum->precision == 0)
				dnum->specifier = 'f';
			else
				dnum->specifier = 'e';
		}
		else
			dnum->specifier = 'f';
		return (1);
	}
	return (0);
}

int		ft_spec_g_convert(t_dnum *dnum)
{
	int		len;
	int		minus_exp;

	minus_exp = 0;
	if (dnum->exponent < 0)
		minus_exp = dnum->exponent;
	len = ft_strlen(dnum->num_str) - 1;
	if (dnum->num_sign != 1)
		while (dnum->num_str[len] && dnum->num_str[len] == '0')
			dnum->num_str[len--] = 0;
	while (len + minus_exp > dnum->precision && dnum->precision != 0)
		dnum->num_str[len--] = 0;
	if (dnum->num_sign != 1)
		while (dnum->num_str[len] && dnum->num_str[len] == '0')
			dnum->num_str[len--] = 0;
	if (dnum->num_str[len] == '.' && dnum->num_sign != 1)
		dnum->num_str[len--] = 0;
	return (1);
}
