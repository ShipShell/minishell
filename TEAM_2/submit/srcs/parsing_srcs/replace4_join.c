/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace4_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:55:34 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/15 14:48:31 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_handled_part(char *result, char *str)
{
	char		*tmp;

	if (result == NULL)
		result = ft_strdup(str);
	else
	{
		tmp = result;
		result = ft_strjoin(tmp, str);
		free(tmp);
	}
	free(str);
	return (result);
}
