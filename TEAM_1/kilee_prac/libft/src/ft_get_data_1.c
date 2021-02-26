/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:33:37 by kilee             #+#    #+#             */
/*   Updated: 2020/11/06 17:17:08 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_get_data(t_conv *conv)
{
	if (conv->specifier == 'c')
		ft_get_data_char(conv);
	else if (conv->specifier == 'd' || conv->specifier == 'i')
		ft_get_data_int(conv);
	else if (conv->specifier == 's')
		ft_get_data_str(conv);
	else if (conv->specifier == 'o' || conv->specifier == 'u'
		|| conv->specifier == 'x' || conv->specifier == 'X')
		ft_get_data_unsigned_int(conv);
	else if (conv->specifier == 'p')
		ft_get_data_pointer(conv);
	else if (conv->specifier == '%')
		ft_get_data_percent(conv);
	else if (conv->specifier == 'f' || conv->specifier == 'e'
			|| conv->specifier == 'g')
		ft_get_data_double(conv);
	else if (conv->specifier == 'n')
	{
		ft_get_data_num(conv);
		return (0);
	}
	return (1);
}

int		ft_get_data_char(t_conv *conv)
{
	char	c;

	c = va_arg(conv->arg_point, int);
	conv->data = ft_strndup(&c, 1);
	return (1);
}

int		ft_get_data_int(t_conv *conv)
{
	long long	num;

	num = va_arg(conv->arg_point, long long);
	ft_int_length_apply(conv, num);
	return (1);
}

int		ft_get_data_unsigned_int(t_conv *conv)
{
	unsigned long long	num;

	num = va_arg(conv->arg_point, unsigned long long);
	if (conv->specifier == 'x' || conv->specifier == 'X')
		ft_unsigned_int_x_length_apply(conv, num);
	else if (conv->specifier == 'u')
		ft_unsigned_int_u_length_apply(conv, num);
	else if (conv->specifier == 'o')
		ft_unsigned_int_o_length_apply(conv, num);
	return (1);
}

int		ft_get_data_str(t_conv *conv)
{
	char	*str;

	str = va_arg(conv->arg_point, char *);
	if (str == NULL)
		conv->data = ft_strdup("(null)");
	else
		conv->data = ft_strdup(str);
	return (1);
}
