/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:44 by kilee             #+#    #+#             */
/*   Updated: 2021/03/16 12:37:32 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*g_env;
t_cmd	*g_cmd;
int		g_exit_code;
t_bool	g_child = 0;

int		main(int argc, char *argv[], char *envp[])
{
	if (argc != 1 || argv == NULL)
	{
		ft_putstr_fd("Error : wrong argument\n", 2);
		return (0);
	}
	ascii_art();
	init_g_env(envp);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	loop_prompt();
	return (0);
}

void	handle_sigint(int signo)
{
	(void)signo;
	if (g_child == 1)
	{
		g_exit_code = 130;
		printf("\n");
	}
	else
	{
		g_exit_code = 1;
		erase_signal_ascii();
		show_prompt_title();
	}
	return ;
}

void	handle_sigquit(int signo)
{
	(void)signo;
	if (g_child == 1)
	{
		g_exit_code = 131;
		printf("Quit: 3\n");
	}
	else
		ft_printf("\b\b  \b\b");
	return ;
}

void	ascii_art(void)
{
	printf(" .--. .-.    _        .--. .-.         .-.  .-.\n");
	printf(": .--': :   :_;      : .--': :         : :  : :\n");
	printf("`. `. : `-. .-..---. `. `. : `-.  .--. : :  : :\n");
	printf(" _`, :: .. :: :: .; ` _`, :: .. :' '_.': :_ : :_\n");
	printf("`.__.':_;:_;:_;: ._.'`.__.':_;:_;`.__.'`.__;`.__;\n");
	printf("               : :        \n");
	printf("               :_;          by kilee 🙉 & hson 👻 \n");
	printf("               __    __    __\n");
	printf("              |==|  |==|  |==|\n");
	printf("            __|__|__|__|__|__|_\n");
	printf("         __|___________________|___\n");
	printf("      __|__[]__[]__[]__[]__[]__[]__|___\n");
	printf("     |............................o.../\n");
	printf("     \\.............................../\n");
	printf(",~')_,~')_,~')_,~')_,~')_,~')_,~')_,~')/,~')_\n");
}
