/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:44 by kilee             #+#    #+#             */
/*   Updated: 2021/02/23 16:34:53 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cntlc(int signo)
{
	printf("signo? :%d\n", signo);
	signal(SIGINT, SIG_DFL);
}

int		main(int argc, char *argv[], char *envp[])
{
	int		i;

	i = -1;
	signal(SIGINT, cntlc);
	while(1)
	;
	return (0);
}
