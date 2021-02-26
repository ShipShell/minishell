/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:28:50 by kilee             #+#    #+#             */
/*   Updated: 2020/11/05 18:35:39 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		ft_align_default(t_conv *conv, int len)
{
	int		gap;
	char	*new;

	gap = conv->width - len;
	if (!(new = (char *)malloc(sizeof(char) * (conv->width + 1))))
		return (0);
	new[conv->width] = '\0';
	ft_memset(new, ' ', gap);
	ft_strlcpy(&new[gap], conv->data, len + 1);
	free(conv->data);
	conv->data = new;
	return (1);
}

int		ft_align_minus(t_conv *conv, int len)
{
	int		gap;
	char	*new;

	gap = conv->width - len;
	if (!(new = (char *)malloc(sizeof(char) * (conv->width + 1))))
		return (0);
	new[conv->width] = '\0';
	ft_strlcpy(new, conv->data, len + 1);
	ft_memset(&new[len], ' ', gap);
	free(conv->data);
	conv->data = new;
	return (1);
}

int		ft_align_zero(t_conv *conv, int len)
{
	int		gap;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	gap = conv->width - len;
	if (!(new = (char *)malloc(sizeof(char) * (conv->width + 1))))
		return (0);
	new[conv->width] = '\0';
	if (conv->data[j] == '+' || conv->data[j] == '-'
		|| conv->data[j] == ' ')
		new[i++] = conv->data[j++];
	if ((conv->specifier == 'x' || conv->specifier == 'X')
		&& !ft_strchr_only(conv->data, '0') && conv->f_num_sign == 1)
	{
		new[i++] = conv->data[j++];
		new[i++] = conv->data[j++];
	}
	ft_memset(&new[i], '0', gap);
	ft_strlcpy(&new[gap + i], &conv->data[j], len + 1 - i);
	free(conv->data);
	conv->data = new;
	return (1);
}

int		ft_align(t_conv *conv)
{
	int		len;

	len = ft_strlen(conv->data);
	if (conv->specifier == 'c' && len == 0)
		len = 1;
	if (conv->width > len)
	{
		if (conv->f_minus == 1)
			ft_align_minus(conv, len);
		else if (conv->f_zero == 1 && (conv->precision == -1024566431
				|| ft_strchr(FEGP, conv->specifier)))
			ft_align_zero(conv, len);
		else
			ft_align_default(conv, len);
		return (1);
	}
	return (0);
}
