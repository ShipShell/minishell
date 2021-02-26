/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:43:48 by hson              #+#    #+#             */
/*   Updated: 2020/11/17 11:23:18 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_wd_or_prc(va_list ap, t_format *form, const char c)
{
	if (form->prec == -1)
	{
		if (c == '*')
		{
			form->width = va_arg(ap, int);
			if (form->width < 0)
			{
				form->width *= -1;
				form->minus = 1;
			}
		}
		else if (ft_isdigit(c))
			form->width = form->width * 10 + c - '0';
	}
	else
	{
		if (c == '*')
			form->prec = va_arg(ap, int);
		else if (ft_isdigit(c))
			form->prec = form->prec * 10 + c - '0';
	}
}

int		fill_format(va_list ap, t_format *form, const char *format, int i)
{
	while (format[++i] && !(ft_strchr(TYPE, format[i])))
	{
		if (format[i] == '0' && form->width == 0 && form->prec == -1)
			form->zero = 1;
		else if (format[i] == '-' && form->prec == -1)
			form->minus = 1;
		else if (format[i] == '.')
			form->prec = 0;
		else if (format[i] == '*' || ft_isdigit(format[i]))
			is_wd_or_prc(ap, form, format[i]);
	}
	return (i);
}

int		print_format(va_list ap, t_format *form)
{
	int res;

	res = 0;
	if (form->type == 'c')
		res = print_char(va_arg(ap, int), form);
	else if (form->type == 's')
		res = print_str(va_arg(ap, char *), form);
	else if (form->type == 'd' || form->type == 'i')
		res = print_integer(va_arg(ap, int), form);
	else if (form->type == 'u' || form->type == 'x' || form->type == 'X')
		res = print_unsigned(va_arg(ap, unsigned int), form);
	else if (form->type == 'p')
		res = print_unsigned(va_arg(ap, unsigned long long), form);
	else if (form->type == '%')
		res = print_str("%", form);
	return (res);
}

int		parsing_format(va_list ap, const char *format)
{
	t_format	*form;
	int			res;
	int			i;

	res = 0;
	i = 0;
	if (!(form = malloc(sizeof(t_format))))
		return (-1);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			res += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_form(form);
			i = fill_format(ap, form, format, i);
			if (format[i])
				form->type = format[i++];
			if (form->minus == 1)
				form->zero = 0;
			res += print_format(ap, form);
		}
	}
	free(form);
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = parsing_format(ap, format);
	va_end(ap);
	return (res);
}
