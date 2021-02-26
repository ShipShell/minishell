/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:24:35 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 19:14:12 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int			ft_star_to_width(t_conv *conv)
{
	conv->width = va_arg(conv->arg_point, int);
	if (conv->width < 0)
	{
		conv->width *= -1;
		conv->f_minus = 1;
	}
	return (1);
}

int			ft_star_to_precision(t_conv *conv)
{
	conv->precision = va_arg(conv->arg_point, int);
	return (1);
}
