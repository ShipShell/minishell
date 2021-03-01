/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:27:13 by hson              #+#    #+#             */
/*   Updated: 2020/11/17 13:43:10 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_nbr_base(unsigned long long nbr, unsigned long long base
						, char type)
{
	char	*res;
	int		res_len;
	int		i;

	res_len = ft_baselen(nbr, base);
	if (!(res = (char *)malloc(sizeof(char) * res_len + 1)))
		return (0);
	res[res_len] = '\0';
	i = 1;
	if (nbr == 0)
		res[res_len - 1] = '0';
	while (nbr > 0)
	{
		res[res_len - i] = ft_base(base, type)[nbr % base];
		nbr /= base;
		i++;
	}
	return (res);
}

char	*put_unsigned_prec(char *save, char *nbr_base, int len, t_format *form)
{
	int	nbr_len;
	int i;
	int j;

	nbr_len = ft_strlen(nbr_base);
	i = 0;
	j = 0;
	if (form->prec > nbr_len)
	{
		while (i < form->prec - nbr_len)
			save[i++] = '0';
	}
	if (form->prec == 0 && nbr_base[0] == '0')
		save[i++] = '\0';
	while (i < len)
		save[i++] = nbr_base[j++];
	save[i] = '\0';
	return (save);
}

char	*put_unsigned(unsigned long long nbr, t_format *form)
{
	char	*save;
	char	*nbr_base;
	int		nbr_len;
	int		len;

	nbr_base = get_nbr_base(nbr, form->nbr_base, form->type);
	nbr_len = ft_strlen(nbr_base);
	len = nbr_len >= form->prec ? nbr_len : form->prec;
	if (!(save = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	save = put_unsigned_prec(save, nbr_base, len, form);
	free(nbr_base);
	return (save);
}

int		print_unsigned(unsigned long long nbr, t_format *form)
{
	int		res;
	char	*save;
	char	*tmp;

	if (form->type == 'x' || form->type == 'X' || form->type == 'p')
		form->nbr_base = 16;
	save = put_unsigned(nbr, form);
	tmp = 0;
	if (form->type == 'p')
	{
		tmp = save;
		save = ft_strjoin("0x", save);
		free(tmp);
	}
	if (form->prec > -1)
		form->zero = 0;
	res = put_width_str(save, form);
	free(save);
	return (res);
}
