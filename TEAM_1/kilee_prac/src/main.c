/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kihoonlee <kihoonlee@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:44 by kilee             #+#    #+#             */
/*   Updated: 2021/02/24 14:50:11 by kihoonlee        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cntlc(int signo)
{
	printf("signo? :%d\n", signo);
	signal(SIGINT, SIG_DFL);
}


/*
** 프롬프트 띄우는 함수
** 이름 : prompt_show()
** 1. shipshell$
*/
// int		main(int argc, char *argv[], char *envp[])
// {
// 	int		i;

// 	i = -1;
// 	signal(SIGINT, cntlc);
// 	while(1)
// 	;
// 	return (0);
// }

int		main(int argc, char *argv[], char *envp[])
{
	int		i;

	i = -1;
	while(envp[++i])
	{
		printf("%s\n", envp[i]);
	}
	return (0);
}
