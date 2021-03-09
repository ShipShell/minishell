// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   replace.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/03/05 14:50:11 by hyeonkim          #+#    #+#             */
// /*   Updated: 2021/03/09 15:43:46 by hyeonkim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

// static int	check_whether_replace_or_not(char c, t_quoting quoting)
// {
// 	if ((c == '$' || c == '~')
// 		&& quoting.quotes != SINGLE_OPEN && quoting.old_escape == OFF)
// 		return (1);
// 	else
// 		return (0);
// }

static int	get_len_to_replace(char *str)
{
	int			i;
	t_quoting	quoting;

	init_quoting(&quoting);
	i = 0;
	while (str[i])
	{
		change_quoting(str[i], &quoting);
		
		++i;
	}
}

void		replace(char **token)
{
	int		i;

	i = 0;
	while (token[i])
	{
		// printf("token[%d] : %s\n", i, token[i]);
		check_and_replace(token[i]);
		// printf("replaced token[%d] : %s\n", i, token[i]);
		++i;
	}
	printf("\n");
}