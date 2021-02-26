/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:12:42 by mijeong           #+#    #+#             */
/*   Updated: 2020/10/06 19:21:33 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = -1;
    while(str1[++i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    return (str1[i] - str2[i]);
}