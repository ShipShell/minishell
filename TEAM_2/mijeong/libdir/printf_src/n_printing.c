/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_printing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:07:36 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/07 08:56:35 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_printer(t_key *key)
{
	if (key->flag.ll)
		*(va_arg(key->ap, long long int *)) = key->result;
	else if (key->flag.l)
		*(va_arg(key->ap, long int *)) = (long int)key->result;
	else if (key->flag.hh)
		*(va_arg(key->ap, signed char *)) = (signed char)key->result;
	else if (key->flag.h)
		*(va_arg(key->ap, short int *)) = (short int)key->result;
	else
		*(va_arg(key->ap, int *)) = (int)key->result;
	return (0);
}
