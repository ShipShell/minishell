/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:01:27 by mijeong           #+#    #+#             */
/*   Updated: 2021/03/15 18:01:54 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bankround_div(union u_f *result, long long int *front, t_key *key,
					int count)
{
	int			i;
	long long	dig;
	double		temp;

	dig = 1;
	i = 0;
	while (i++ < count)
		dig *= 10;
	temp = ((*result).d * dig * 10);
	if (((long long)temp % 10) > 5)
		(*result).d += 1.0 / dig;
	else if (((long long)temp % 10) < 5)
		;
	else if (bitcheck(*result, key))
	{
		if ((long long)temp / 10 == 0 && *front % 10 % 2 != 0)
			(*result).d = (*result).d + 1.0 / dig;
		if (((long long)temp / 10) % 10 % 2 != 0)
			(*result).d = (*result).d + 1.0 / dig;
	}
	else
		(*result).d = (*result).d + 1.0 / dig;
	return (0);
}
