/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:21:23 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/05 13:39:53 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_fd(long long int n, t_key *key)
{
	char			c;
	long long int	temp;

	temp = n;
	if (n < 0)
		temp *= -1;
	c = temp % 10 + '0';
	if (n / 10 == 0)
		putfunc(c, key);
	else
	{
		ft_putnbr_fd(temp / 10, key);
		putfunc(c, key);
	}
}
