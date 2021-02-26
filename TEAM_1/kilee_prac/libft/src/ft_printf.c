/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:14:18 by kilee             #+#    #+#             */
/*   Updated: 2020/11/06 12:48:34 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_printf(const char *format, ...)
{
	t_conv	*conv;
	int		print_size;

	if (!(conv = (t_conv *)malloc(sizeof(t_conv) * (1))))
		return (-1);
	ft_conv_print_size_init(conv);
	va_start(conv->arg_point, format);
	while (*format)
		if (ft_print_choice(conv, &format) == -1)
			return (-1);
	va_end(conv->arg_point);
	print_size = conv->print_size;
	free(conv);
	return (print_size);
}

int		ft_print_choice(t_conv *conv, const char **format)
{
	if (**format == '%')
	{
		ft_conv_init(conv);
		if (ft_parse(*format + 1, conv) == 0)
			return (-1);
		ft_trans(conv);
		ft_write_conv(conv);
		*format += conv->conv_len + 1;
	}
	else
	{
		write(1, *format, 1);
		++(conv->print_size);
		++(*format);
	}
	return (0);
}

int		ft_parse(const char *format, t_conv *conv)
{
	const char	*format_start;

	format_start = format;
	while (ft_flag_check(format, conv))
		format += 1;
	format += ft_width_check(format, conv);
	format += ft_precision_check(format, conv);
	while (ft_length_check(format, conv))
		format += 1;
	if (ft_specifier_check(format, conv))
	{
		conv->conv_len = format + 1 - format_start;
		return (1);
	}
	return (0);
}

int		ft_trans(t_conv *conv)
{
	if (ft_get_data(conv))
	{
		ft_precision_apply(conv);
		ft_plus(conv);
		ft_space(conv);
		ft_number_sign(conv);
		ft_align(conv);
	}
	return (1);
}
