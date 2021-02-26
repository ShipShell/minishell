/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:42:51 by hson              #+#    #+#             */
/*   Updated: 2020/11/17 12:53:37 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_form(t_format *form)
{
	form->minus = 0;
	form->zero = 0;
	form->width = 0;
	form->prec = -1;
	form->type = 0;
	form->nbr_base = 10;
	form->sign = 0;
}

char	*ft_base(int base, char type)
{
	char	*res;

	res = 0;
	if (base == 10)
		res = "0123456789";
	else if (base == 16 && (type == 'x' || type == 'p'))
		res = "0123456789abcdef";
	else if (base == 16 && type == 'X')
		res = "0123456789ABCDEF";
	return (res);
}

int		ft_baselen(unsigned long long nbr, unsigned long long base)
{
	int i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= base;
	}
	return (i);
}
