/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:39:46 by kilee             #+#    #+#             */
/*   Updated: 2020/11/06 17:17:28 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int			ft_get_data_percent(t_conv *conv)
{
	conv->data = ft_strdup("%");
	return (1);
}

int			ft_get_data_num(t_conv *conv)
{
	int	*print_size;

	print_size = va_arg(conv->arg_point, int*);
	*print_size = conv->print_size;
	return (1);
}

int			ft_get_data_pointer(t_conv *conv)
{
	char	*address;
	char	*temp;

	address = va_arg(conv->arg_point, char*);
	if (address == NULL && conv->precision == -1024566431)
		temp = ft_strdup("0");
	else if (address == NULL)
		temp = ft_strdup("");
	else
		temp = ft_ultoa_base((unsigned long long)address, "0123456789abcdef");
	conv->data = ft_strjoin("0x", temp);
	free(temp);
	return (1);
}

int			ft_get_data_double(t_conv *conv)
{
	t_dnum	*real_num;

	if (!(real_num = (t_dnum *)malloc(sizeof(t_dnum))))
		return (0);
	real_num->num.num = va_arg(conv->arg_point, double);
	real_num->precision = conv->precision;
	real_num->num_sign = conv->f_num_sign;
	real_num->specifier = conv->specifier;
	ft_dtoa(real_num);
	conv->data = real_num->num_str;
	free(real_num);
	real_num = NULL;
	return (1);
}
