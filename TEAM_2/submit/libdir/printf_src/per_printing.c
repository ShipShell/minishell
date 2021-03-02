/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_printing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:00:18 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/08 23:59:47 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	per_align_check(int count, t_key *key)
{
	int		i;
	char	c;

	if (!(key->flag.minus) && key->flag.zero)
		c = '0';
	else
		c = ' ';
	if (count <= key->precision)
		count = key->precision;
	i = -1;
	while (++i < key->width - count)
		putfunc(c, key);
	return (0);
}

int	per_printer(t_key *key)
{
	int	count;
	int	i;

	count = 1;
	i = -1;
	key->precision = -1;
	if (!(key->flag.minus))
		per_align_check(count, key);
	putfunc('%', key);
	if (key->flag.minus)
		per_align_check(count, key);
	return (0);
}
