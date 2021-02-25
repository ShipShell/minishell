/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:24:36 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/10 16:15:22 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	tmp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (long)n * (-1);
	}
	else
		num = (long)n;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	tmp = (num % 10) + '0';
	ft_putchar_fd(tmp, fd);
}
