/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:47:06 by hson              #+#    #+#             */
/*   Updated: 2020/11/17 14:11:01 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_integer(long long nbr, int prec, int nbr_len)
{
	char	*save;
	char	*n_to_s;
	int		len;
	int		i;
	int		j;

	n_to_s = ft_itoa(nbr);
	i = 0;
	j = 0;
	len = nbr_len >= prec ? nbr_len : prec;
	if (!(save = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (prec > nbr_len)
	{
		while (i < prec - nbr_len)
			save[i++] = '0';
	}
	if (prec == 0 && nbr == 0)
		save[i++] = '\0';
	while (i < len)
		save[i++] = n_to_s[j++];
	save[i] = '\0';
	free(n_to_s);
	return (save);
}

int		print_integer(long long nbr, t_format *form)
{
	char	*save;
	int		res;

	if (form->prec > -1)
		form->zero = 0;
	res = 0;
	if (nbr < (long long)0)
	{
		if (form->zero == 1 || form->minus == 1)
			res += ft_putchar('-');
		else
			form->sign = 1;
		form->width -= 1;
		nbr *= -1;
	}
	save = put_integer(nbr, form->prec, ft_nbrlen(nbr));
	res += put_width_str(save, form);
	free(save);
	return (res);
}
