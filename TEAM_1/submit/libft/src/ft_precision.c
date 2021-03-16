/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:17:50 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 19:39:22 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_precision_zero_check(t_conv *conv, int len)
{
	char	*new;

	if (len == 1 && *(conv->data) == '0' && conv->precision == 0)
	{
		if (!(new = (char *)ft_calloc(sizeof(char), 1)))
			return (0);
		free(conv->data);
		conv->data = new;
		return (1);
	}
	return (0);
}

int		ft_precision_diouxx(t_conv *conv)
{
	int		gap;
	char	*new_data;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(conv->data);
	ft_precision_zero_check(conv, len);
	gap = conv->precision - len;
	if (*(conv->data) == '-')
		++gap;
	if (gap <= 0)
		return (0);
	i = 0;
	j = 0;
	if (!(new_data = (char *)ft_calloc(sizeof(char), (len + gap + 1))))
		return (0);
	if ((conv->data)[j] == '-' || (conv->data)[j] == '+')
		new_data[i++] = (conv->data)[j++];
	while (gap--)
		new_data[i++] = '0';
	ft_strlcat(&new_data[i], &((conv->data)[j]), len + 1);
	free(conv->data);
	conv->data = new_data;
	return (1);
}

int		ft_precision_string(t_conv *conv)
{
	int		len;
	char	*new_str;

	len = ft_strlen(conv->data);
	if (conv->precision < len)
	{
		if (!(new_str = (char *)malloc(sizeof(char) * (conv->precision + 1))))
			return (0);
		ft_strlcpy(new_str, conv->data, conv->precision + 1);
		free(conv->data);
		conv->data = new_str;
	}
	return (1);
}

int		ft_precision_pointer(t_conv *conv)
{
	int		len;
	char	*temp;
	int		i;

	len = ft_strlen(conv->data);
	i = -1;
	temp = conv->data;
	if (conv->precision < 0)
	{
		conv->data = ft_strjoin(temp, "0");
		free(temp);
	}
	else if (conv->precision > len - 2)
	{
		if (!(conv->data = (char *)malloc(sizeof(char) * conv->precision + 3)))
			return (0);
		while (++i < 2)
			conv->data[i] = temp[i];
		while (i < conv->precision - len + 4)
			conv->data[i++] = '0';
		ft_strlcpy(&conv->data[i], &temp[2], len + 1);
		conv->data[conv->precision + 2] = '\0';
		free(temp);
	}
	return (1);
}

int		ft_precision_apply(t_conv *conv)
{
	if (conv->precision == -1024566431)
		return (0);
	if (ft_strchr(DIOUXX, conv->specifier))
		ft_precision_diouxx(conv);
	else if (conv->specifier == 's')
		ft_precision_string(conv);
	else if (conv->specifier == 'p')
		ft_precision_pointer(conv);
	return (1);
}
