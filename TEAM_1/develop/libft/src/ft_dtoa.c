/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:31:55 by kilee             #+#    #+#             */
/*   Updated: 2020/11/06 19:37:50 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_dtoa(t_dnum *dnum)
{
	if (ft_nan_check(dnum))
		return (1);
	if (dnum->precision < 0)
		dnum->precision = 6;
	ft_dtoa_get_exponent(dnum);
	ft_dtoa_get_figure(dnum);
	dnum->is_g = ft_spec_g_check(dnum);
	if (dnum->num.num == 0)
		ft_dtoa_zero(dnum);
	else
	{
		ft_round_up(dnum);
		ft_get_num_str(dnum);
		ft_put_dot_and_zero(dnum);
		if (dnum->is_g == 1)
			ft_spec_g_convert(dnum);
		if (dnum->specifier == 'e')
			ft_join_exp(dnum);
	}
	ft_dtoa_join_sign(dnum);
	return (1);
}

int		ft_dtoa_zero(t_dnum *dnum)
{
	if (dnum->precision == 0 || (dnum->is_g && dnum->num_sign == 0))
	{
		if (!(dnum->num_str = (char *)malloc(dnum->num_sign + 2)))
			return (0);
		dnum->num_str[0] = '0';
		if (dnum->num_sign)
			dnum->num_str[1] = '.';
		dnum->num_str[dnum->num_sign + 1] = '\0';
	}
	else
	{
		if (!(dnum->num_str = (char *)malloc(dnum->precision + 3 - dnum->is_g)))
			return (0);
		ft_memset(dnum->num_str, '0', dnum->precision + 2 - dnum->is_g);
		dnum->num_str[1] = '.';
		dnum->num_str[dnum->precision + 2 - dnum->is_g] = '\0';
	}
	if (dnum->specifier == 'e')
		ft_join_exp(dnum);
	return (1);
}

int		ft_put_zero_back(t_dnum *dnum)
{
	char	*temp;
	char	*new_str;
	int		zero_count;
	int		num_str_len;

	temp = ft_strchr(dnum->num_str, '.') + 1;
	zero_count = dnum->precision - ft_strlen(temp);
	if (zero_count > 0)
	{
		num_str_len = ft_strlen(dnum->num_str);
		if (!(temp = (char *)malloc(zero_count + 1)))
			return (0);
		ft_memset(temp, '0', zero_count);
		temp[zero_count] = '\0';
		new_str = ft_strjoin(dnum->num_str, temp);
		free(dnum->num_str);
		free(temp);
		dnum->num_str = new_str;
	}
	return (1);
}

int		ft_put_dot_and_zero(t_dnum *dnum)
{
	char	*temp;
	int		dot_index;

	dot_index = 1;
	if (dnum->precision != 0 || dnum->num_sign == 1)
	{
		if (dnum->specifier == 'f')
		{
			if (dnum->exponent > 0)
				dot_index += dnum->exponent;
			temp = ft_needle(dnum->num_str, ".", dot_index);
		}
		else
			temp = ft_needle(dnum->num_str, ".", 1);
	}
	else if (dnum->is_g == 1)
		temp = ft_needle(dnum->num_str, ".", 1);
	else
		return (0);
	free(dnum->num_str);
	dnum->num_str = temp;
	ft_put_zero_back(dnum);
	return (1);
}

int		ft_dtoa_join_sign(t_dnum *dnum)
{
	char	*new;

	if (dnum->num.s_bit.sign_bit == 0)
		return (1);
	if (!(new = ft_strjoin("-", dnum->num_str)))
		return (0);
	free(dnum->num_str);
	dnum->num_str = new;
	return (1);
}
