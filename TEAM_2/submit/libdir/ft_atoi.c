/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:23:48 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/22 09:16:41 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *cstr)
{
	int			i;
	int			key;
	int			count;
	long long	result;

	count = 0;
	result = 0;
	key = 0;
	i = 0;
	while (cstr[i] == ' ' || (cstr[i] >= 9 && cstr[i] <= 13))
		i++;
	if (cstr[i] == '-' || cstr[i] == '+')
	{
		key = cstr[i] == '-' ? 1 : 0;
		i++;
	}
	while (cstr[i] >= '0' && cstr[i] <= '9' && cstr[i])
	{
		result = result * 10 + cstr[i] - '0';
		count++;
		i++;
	}
	if (count >= 19)
		return (key ? 0 : -1);
	return (key ? result * -1 : result);
}
