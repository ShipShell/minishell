/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace6_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:56:03 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/12 14:02:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_whether_replace(char c, t_quoting quoting)
{
	int		replace_check;

	change_quoting(c, &quoting);
	if (c == '$'
		&& quoting.quotes != SINGLE_OPEN && quoting.old_escape == OFF)
		replace_check = DOLLAR_ON;
	else if (c == '~'
		&& quoting.quotes != SINGLE_OPEN && quoting.old_escape == OFF)
		replace_check = WAVE_ON;
	else
		replace_check = NOT_TO_REPLACE;
	return (replace_check);
}
