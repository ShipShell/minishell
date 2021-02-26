/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:17:43 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 18:47:17 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_flag_check(const char *format, t_conv *conv)
{
	if (*format == '-')
		conv->f_minus = 1;
	else if (*format == '0')
		conv->f_zero = 1;
	else if (*format == ' ')
		conv->f_space = 1;
	else if (*format == '+')
		conv->f_plus = 1;
	else if (*format == '#')
		conv->f_num_sign = 1;
	else
		return (0);
	return (1);
}

int		ft_width_check(const char *format, t_conv *conv)
{
	int		len;
	char	*width;

	len = 0;
	if (format[len] >= '1' && format[len] <= '9')
	{
		while (ft_isdigit(format[len]))
			++len;
		width = ft_strndup(format, len);
		conv->width = ft_atoi(width);
		free(width);
		return (len);
	}
	else if (format[len] == '*')
	{
		ft_star_to_width(conv);
		return (1);
	}
	return (0);
}

int		ft_precision_check(const char *format, t_conv *conv)
{
	int		len;
	char	*prec;

	len = 0;
	if (*(format++) == '.')
	{
		if (*format == '*')
		{
			ft_star_to_precision(conv);
			if (conv->precision < 0)
				conv->precision = -1024566431;
			return (2);
		}
		if (format[len] == '-')
			++len;
		while (ft_isdigit(format[len]))
			++len;
		prec = ft_strndup(format, len);
		conv->precision = ft_atoi(prec);
		free(prec);
		return (len + 1);
	}
	return (0);
}

int		ft_length_check(const char *format, t_conv *conv)
{
	if (*format == 'h')
		conv->length -= 1;
	else if (*format == 'l')
		conv->length += 1;
	else
		return (0);
	return (1);
}

int		ft_specifier_check(const char *format, t_conv *conv)
{
	if (*format && ft_strchr(SPECIFIER, *format))
	{
		conv->specifier = *format;
		return (1);
	}
	return (0);
}
