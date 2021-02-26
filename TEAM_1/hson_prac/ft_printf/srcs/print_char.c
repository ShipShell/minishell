/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:46:17 by hson              #+#    #+#             */
/*   Updated: 2020/10/26 20:06:57 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_width(char c, int width, int minus, int zero)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (minus == 1)
	{
		res += ft_putchar(c);
		while (++i < width)
			res += ft_putchar(' ');
	}
	else
	{
		while (i++ < width - 1)
		{
			if (zero == 1)
				res += ft_putchar('0');
			else
				res += ft_putchar(' ');
		}
		res += ft_putchar(c);
	}
	return (res);
}

int	print_char(int c, t_format *form)
{
	int res;

	res = put_width(c, form->width, form->minus, form->zero);
	return (res);
}
