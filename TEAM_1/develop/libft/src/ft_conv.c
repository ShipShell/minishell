/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:17:43 by kilee             #+#    #+#             */
/*   Updated: 2020/11/06 11:15:31 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_conv_init(t_conv *conv)
{
	conv->specifier = 0;
	conv->f_minus = 0;
	conv->f_zero = 0;
	conv->f_space = 0;
	conv->f_plus = 0;
	conv->f_num_sign = 0;
	conv->precision = -1024566431;
	conv->width = 0;
	conv->length = 0;
	conv->conv_len = 0;
	conv->data = NULL;
}

void	ft_conv_print_size_init(t_conv *conv)
{
	conv->print_size = 0;
}

int		ft_write_conv(t_conv *conv)
{
	int	write_size;

	if (conv->specifier == 'n')
		return (0);
	write_size = ft_strlen(conv->data);
	if (conv->width > write_size)
		write_size = conv->width;
	else if (conv->specifier == 'c' && write_size == 0)
		write_size = 1;
	write(1, conv->data, write_size);
	conv->print_size += write_size;
	free(conv->data);
	return (1);
}
