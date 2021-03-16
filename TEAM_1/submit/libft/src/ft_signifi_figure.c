/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signifi_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:07:34 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 19:31:23 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_signifi_figure(long long num)
{
	int	count;

	count = 0;
	while (num)
	{
		if (num % 10 != 0)
			++count;
		num /= 10;
	}
	return (count);
}
