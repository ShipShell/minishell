/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:00:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/02/26 17:00:13 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

// void		test_cmd_list(t_list *cmd_list)
// {
// 	int		i = 0;
	
// 	while (cmd_list != NULL)
// 	{
// 		printf("cmd : %s\n", ((t_data *)cmd_list->content)->cmd);
// 		while (((t_data *)cmd_list->content)->arg->content != NULL)
// 		{
// 			printf("arg %d : %s\n", i, ((char *)((t_data *)cmd_list->content)->arg));
// 			((t_data *)cmd_list->content)->arg = ((t_data *)cmd_list->content)->arg->next;
// 			++i;
// 		}
// 		cmd_list = cmd_list->next;
// 	}
// }

t_data		*save_data(char *sep_by_colon)
{
	int		index;
	char	**token;
	t_data	*result;
	int 	i = -1;
	
	index = 0;
	result = (t_data *)malloc(sizeof(t_data));
	token = ft_split(sep_by_colon, ' ');
	result->cmd = token[0];
	result->arg = ft_lstnew(token[++i]);
	while (token[++index] != NULL)
		ft_lstadd_back(&result->arg, ft_lstnew(token[index]));
		// printf("%s\n", token[index]);
	// free (token);
	return (result);
}

void	seperate_cmdline(char *stdin_buf, t_list *cmd_list)
{
	while ()
	// test_cmd_list(cmd_list);
	// free (sep_by_pipe);
	// free (sep_by_colon);
}

void	show_prompt()
{
	ft_putstr_fd("shipshell$ ", 1);
}

int		wait_cmd(void)
{
	char	*stdin_buf;
	t_list	*cmd_list;

	show_prompt();
	get_next_line(0, &stdin_buf);
	if (ft_strncmp(stdin_buf, "exit", 4) == 0)
		exit(0);
	seperate_cmdline(stdin_buf, cmd_list);
	return (0);
}

void	prompt_loop(void)
{
	while(1)
		wait_cmd();
}

void	handle_sigint(int signo)
{
	ft_putstr_fd("\b\b  \b\b\n", 1);
	ft_putstr_fd("shipshell$ ", 1);
	return ;
}

int		main(int argc, char **argv, char **envp)
{
	set_env_list(envp);
	t_list	*test;
	
	test = g_env;
	// while (test != NULL)
	// {
	// 	printf("%s\n", (char *)((t_env *)test->content)->key);
	// 	test = test->next;	
	// }
	signal(SIGINT, handle_sigint);
	prompt_loop();
	return (0);
}