/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:56:30 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/05 13:34:45 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putfunc(char c, t_key *key)
{
	write(1, &c, 1);
	key->result++;
}