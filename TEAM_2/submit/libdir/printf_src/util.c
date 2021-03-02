/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:54:35 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/07 08:32:36 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						d_util(t_key *key, long long int result)
{
	if (result < 0)
		putfunc('-', key);
	else if (key->flag.plus)
		putfunc('+', key);
	else if (key->flag.space)
		putfunc(' ', key);
	return (0);
}

int						x_util(t_key *key, int ul_switch,
								unsigned long long int result)
{
	if (result != 0)
	{
		if (ul_switch == 0)
		{
			write(1, "0x", 2);
			key->result += 2;
		}
		else if (ul_switch == 1)
		{
			write(1, "0X", 2);
			key->result += 2;
		}
	}
	return (0);
}

int						f_util(t_key *key, unsigned long sign)
{
	if (sign != 0)
		putfunc('-', key);
	else if (key->flag.plus)
		putfunc('+', key);
	else if (key->flag.space)
		putfunc(' ', key);
	return (0);
}

long long int			hl_check(t_key *key, long long int result)
{
	if (key->flag.ll == 1)
		return (result);
	else if (key->flag.l == 1)
		return ((long int)result);
	else if (key->flag.hh == 1)
		return ((signed char)result);
	else if (key->flag.h == 1)
		return ((short int)result);
	else
		return ((int)result);
}

unsigned long long int	uhl_check(t_key *key, unsigned long long int result)
{
	if (key->flag.ll == 1)
		return (result);
	else if (key->flag.l == 1)
		return ((unsigned long int)result);
	else if (key->flag.hh == 1)
		return ((unsigned char)result);
	else if (key->flag.h == 1)
		return ((unsigned short int)result);
	else
		return ((unsigned int)result);
}
