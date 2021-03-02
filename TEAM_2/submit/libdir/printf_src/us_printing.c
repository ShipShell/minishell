/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   us_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 08:52:09 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/07 08:46:19 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_align_check(int count, t_key *key)
{
	int		i;
	int		len;
	char	c;

	i = -1;
	if (key->flag.zero && !(key->flag.minus))
		c = '0';
	else
		c = ' ';
	if (key->precision >= count || key->precision == -1)
		len = key->width - count;
	else
		len = key->width - key->precision;
	while (++i < len)
		putfunc(c, key);
	return (0);
}

int		s_printer(t_key *key)
{
	char	*result;
	int		i;
	int		count;

	i = 0;
	result = va_arg(key->ap, char *);
	count = 0;
	if (!result)
		result = "(null)";
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

int		u_align_check(int count, t_key *key, unsigned long long int result)
{
	int		i;
	char	c;

	if (key->flag.zero && key->precision == -1 && !key->flag.minus)
		c = '0';
	else
		c = ' ';
	if (count <= key->precision)
		count = key->precision;
	i = -1;
	while (++i < key->width - count)
		putfunc(c, key);
	if (key->width > 0 && result == 0 && key->precision == 0)
		putfunc(' ', key);
	return (0);
}

void	ft_putunbr_fd(unsigned long long int n, t_key *key)
{
	char				c;
	unsigned long long	temp;

	temp = n;
	c = temp % 10 + '0';
	if (n / 10 == 0)
		putfunc(c, key);
	else
	{
		ft_putunbr_fd(temp / 10, key);
		putfunc(c, key);
	}
}

int		u_printer(t_key *key)
{
	unsigned long long int	result;
	unsigned long long int	temp;
	int						i;
	int						count;

	result = uhl_check(key, va_arg(key->ap, unsigned long long int));
	temp = result;
	count = 1;
	while (temp /= 10)
		count++;
	if (!(key->flag.minus))
		u_align_check(count, key, result);
	i = -1;
	while (++i < key->precision - count)
		putfunc('0', key);
	if (!(key->precision == 0 && result == 0))
		ft_putunbr_fd(result, key);
	if (key->flag.minus)
		u_align_check(count, key, result);
	return (0);
}
