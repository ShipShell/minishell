/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:46:36 by hson              #+#    #+#             */
/*   Updated: 2020/11/17 14:18:29 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_flags(int res, t_format *form, int s_len)
{
	int	i;

	i = 0;
	if (form->minus == 1)
	{
		while (i++ < form->width - s_len)
			res += ft_putchar(' ');
	}
	else
	{
		while (i++ < form->width - s_len)
		{
			if (form->zero == 1)
				res += ft_putchar('0');
			else
				res += ft_putchar(' ');
		}
	}
	return (res);
}

int		put_width_str(char *save, t_format *form)
{
	int	s_len;
	int res;

	s_len = ft_strlen(save);
	res = 0;
	if (form->minus == 1)
	{
		res += ft_putstr(save);
		res = print_flags(res, form, s_len);
	}
	else
	{
		res = print_flags(res, form, s_len);
		if (form->sign == 1)
			res += ft_putchar('-');
		res += ft_putstr(save);
	}
	return (res);
}

char	*put_string(char *str, int prec, int str_len)
{
	char	*save;
	int		len;
	int		i;

	len = str_len > prec ? prec : str_len;
	save = (char *)malloc(sizeof(char) * len + 1);
	if (!save)
		return (0);
	i = 0;
	while (i < len)
	{
		save[i] = str[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

int		print_str(char *str, t_format *form)
{
	char	*save;
	int		res;

	if (!str)
		str = "(null)";
	if (form->prec <= -1 || form->type == '%')
		form->prec = ft_strlen(str);
	if (form->prec != 0)
		save = put_string(str, form->prec, ft_strlen(str));
	else
		save = ft_strdup("");
	res = put_width_str(save, form);
	free(save);
	return (res);
}
