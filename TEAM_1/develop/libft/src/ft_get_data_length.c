/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:33:37 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 18:44:36 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_int_length_apply(t_conv *conv, long long num)
{
	if (conv->length == -1)
		conv->data = ft_itoa((short)num);
	else if (conv->length == -2)
		conv->data = ft_itoa((char)num);
	else if (conv->length == 1)
		conv->data = ft_ltoa((long)num);
	else if (conv->length == 2)
		conv->data = ft_ltoa(num);
	else
		conv->data = ft_itoa((int)num);
	return (1);
}

int		ft_unsigned_int_x_length_apply(t_conv *conv, unsigned long long num)
{
	int	i;

	if (conv->length == -1)
		conv->data = ft_ultoa_base((unsigned short)num, HEX);
	else if (conv->length == -2)
		conv->data = ft_ultoa_base((unsigned char)num, HEX);
	else if (conv->length == 1)
		conv->data = ft_ultoa_base((unsigned long)num, HEX);
	else if (conv->length == 2)
		conv->data = ft_ultoa_base(num, HEX);
	else
		conv->data = ft_ultoa_base((unsigned int)num, HEX);
	if (conv->specifier == 'X')
	{
		i = -1;
		while (conv->data[++i])
			conv->data[i] = ft_toupper(conv->data[i]);
	}
	return (1);
}

int		ft_unsigned_int_o_length_apply(t_conv *conv, unsigned long long num)
{
	if (conv->length == -1)
		conv->data = ft_ultoa_base((unsigned short)num, OCTAL);
	else if (conv->length == -2)
		conv->data = ft_ultoa_base((unsigned char)num, OCTAL);
	else if (conv->length == 1)
		conv->data = ft_ultoa_base((unsigned long)num, OCTAL);
	else if (conv->length == 2)
		conv->data = ft_ultoa_base(num, OCTAL);
	else
		conv->data = ft_ultoa_base((unsigned int)num, OCTAL);
	return (1);
}

int		ft_unsigned_int_u_length_apply(t_conv *conv, unsigned long long num)
{
	if (conv->length == -1)
		conv->data = ft_ultoa((unsigned short)num);
	else if (conv->length == -2)
		conv->data = ft_ultoa((unsigned char)num);
	else if (conv->length == 1)
		conv->data = ft_ultoa((unsigned long)num);
	else if (conv->length == 2)
		conv->data = ft_ultoa(num);
	else
		conv->data = ft_ultoa((unsigned int)num);
	return (1);
}
