/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:33:16 by kilee             #+#    #+#             */
/*   Updated: 2020/11/06 19:56:13 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_plus(t_conv *conv)
{
	int		len;
	char	*new;

	if (!ft_strncmp(conv->data, "nan", 3) || !ft_strncmp(conv->data, "inf", 3))
		return (0);
	if (ft_strchr(SIGNED, conv->specifier)
		&& conv->f_plus == 1 && *(conv->data) != '-')
	{
		len = ft_strlen(conv->data);
		if (!(new = (char *)malloc(sizeof(char) * (len + 2))))
			return (0);
		new[0] = '+';
		ft_strlcpy(&new[1], conv->data, len + 1);
		free(conv->data);
		conv->data = new;
		return (1);
	}
	return (0);
}

int		ft_space(t_conv *conv)
{
	int		len;
	char	*new;

	if (ft_strchr(SIGNED, conv->specifier) && *(conv->data) != '-'
		&& conv->f_plus == 0 && conv->f_space == 1)
	{
		len = ft_strlen(conv->data);
		if (!(new = (char *)malloc(sizeof(char) * (len + 2))))
			return (0);
		new[0] = ' ';
		ft_strlcpy(&new[1], conv->data, len + 1);
		free(conv->data);
		conv->data = new;
		return (1);
	}
	return (0);
}

int		ft_number_sign(t_conv *conv)
{
	int		len;
	char	*new;
	int		eight;

	eight = (conv->specifier == 'o') ? 1 : 0;
	len = ft_strlen(conv->data);
	if (ft_strchr(UNSIGNED, conv->specifier)
		&& conv->f_num_sign == 1 && !ft_strchr_only(conv->data, '0'))
	{
		if (!(new = (char *)malloc(sizeof(char) * (len + 3 - eight))))
			return (0);
		new[0] = '0';
		if (conv->specifier != 'o')
			new[1] = (conv->specifier == 'x') ? 'x' : 'X';
		ft_strlcpy(&new[2 - eight], conv->data, len + 1);
		free(conv->data);
		conv->data = new;
		return (1);
	}
	return (0);
}
