/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev_mj <dev_mj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:12:42 by mijeong           #+#    #+#             */
/*   Updated: 2021/03/06 14:25:30 by dev_mj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = -1;
    if (str1 == 0 || str2 == 0)
        return (-1);
    while(str1[++i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    return (str1[i] - str2[i]);
}