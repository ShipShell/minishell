/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:31:08 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 19:31:12 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double base, int exponent)
{
	double num;

	num = 1.0;
	if (exponent >= 0)
	{
		while (exponent--)
			num *= base;
	}
	else
	{
		while (exponent++)
			num /= base;
	}
	return (num);
}
