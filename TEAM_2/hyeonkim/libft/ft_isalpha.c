/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:28:19 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/10/09 15:21:25 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int tmp;

	tmp = c;
	if (ft_toupper(c) != tmp)
		return (c);
	else if (ft_tolower(c) != tmp)
		return (c);
	else
		return (0);
}
