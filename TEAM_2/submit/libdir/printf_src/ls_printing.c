/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:56:26 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/08 23:58:20 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ls_printer(t_key *key)
{
	wchar_t	*result;
	int		i;
	int		count;

	i = 0;
	result = va_arg(key->ap, wchar_t *);
	count = 0;
	if (!result)
		result = (wchar_t *)"(null)";
	while (result[count])
		count++;
	if (!(key->flag.minus))
		s_align_check(count, key);
	while (result[i] && (i < key->precision || key->precision == -1))
		putfunc(result[i++], key);
	if (key->flag.minus)
		s_align_check(count, key);
	return (0);
}
