/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:27:33 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/15 08:40:08 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

static int	ft_ispoint(char c)
{
	if (c == '.')
		return (1);
	else
		return (0);
}

int			ft_isdouble(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	while (ft_issign(str[++i]))
		sign *= -1;
	while (ft_isdigit(str[i]))
		++i;
	if (ft_ispoint(str[i]))
		++i;
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] == '\0')
		return (1);
	return (0);
}
