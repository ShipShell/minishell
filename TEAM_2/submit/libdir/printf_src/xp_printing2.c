/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xp_printing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:18:23 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/07 08:31:41 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_align_check(int count, t_key *key, unsigned long long int result)
{
	int		i;
	char	c;

	if (key->flag.zero && key->precision == -1 && !(key->flag.minus))
		c = '0';
	else
		c = ' ';
	if (count <= key->precision)
		count = key->precision;
	i = -1;
	if (key->flag.plus || key->flag.space)
		i++;
	if (key->flag.pound && result != 0)
		i += 2;
	while (++i < key->width - count)
		putfunc(c, key);
	if (key->width > 0 && result == 0 && key->precision == 0)
		putfunc(' ', key);
	return (0);
}
