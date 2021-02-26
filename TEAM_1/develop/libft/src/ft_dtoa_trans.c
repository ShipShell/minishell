/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_trans.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:00:25 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/11/06 16:39:09 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_join_exp(t_dnum *dnum)
{
	char	*new;
	int		len;
	int		exp;

	exp = dnum->exponent;
	len = ft_strlen(dnum->num_str);
	if (!(new = (char *)malloc(sizeof(char) * (len + 5))))
		return (0);
	ft_memcpy(new, dnum->num_str, len);
	new[len++] = 'e';
	new[len++] = (exp >= 0) ? '+' : '-';
	if (exp < 0)
		exp *= -1;
	new[len++] = exp / 10 + '0';
	new[len++] = exp % 10 + '0';
	new[len] = '\0';
	free(dnum->num_str);
	dnum->num_str = new;
	return (1);
}

int		ft_num_str_f_exponent_apply(t_dnum *dnum)
{
	char	*zero_str;
	char	*temp;

	if (dnum->exponent < 0 && dnum->figure > 0)
	{
		if (!(zero_str = (char *)malloc(dnum->exponent * -1 + 1)))
			return (0);
		ft_memset(zero_str, '0', dnum->exponent * -1);
		zero_str[dnum->exponent * -1] = '\0';
		temp = ft_strjoin(zero_str, dnum->num_str);
		free(dnum->num_str);
		free(zero_str);
		dnum->num_str = temp;
	}
	return (1);
}

int		ft_num_str_e_precision_apply(t_dnum *dnum)
{
	if ((int)ft_strlen(dnum->num_str) > dnum->precision + 1)
		dnum->num_str[dnum->precision + 1] = '\0';
	return (1);
}

int		ft_get_num_str(t_dnum *dnum)
{
	if (!(dnum->num_str = ft_ltoa(dnum->figure)))
		return (0);
	if (dnum->specifier == 'f')
		ft_num_str_f_exponent_apply(dnum);
	else
		ft_num_str_e_precision_apply(dnum);
	return (1);
}
