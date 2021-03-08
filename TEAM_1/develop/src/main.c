/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:44 by kilee             #+#    #+#             */
/*   Updated: 2021/03/08 20:22:02 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_env	*g_env;
t_cmd	*g_cmd;
int		g_exit_code;

int		show_prompt_title(void)
{
	ft_putstr_fd("shipshell$ ", 1);
	return (0);
}

void	get_prompt_input(char **stdin_buffer)
{
	get_next_line(0, stdin_buffer);
}

int		init_prompt(void)
{
	char	*stdin_buffer;
	int		input_byte;
	t_list	*tokens;

	//delete_cmd_list(&g_cmd, delete_data_in_cmd);
	//show_prompt_title();
	//get_prompt_input(&stdin_buffer);
	//parse_and_split_from_input(stdin_buffer);
	//free(stdin_buffer);

	g_cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	//redir 임의
	// g_cmd->redir_in = 0;
	g_cmd->redir_in = (t_redir *)malloc(sizeof(t_redir) * 1);
	g_cmd->redir_out = (t_redir *)malloc(sizeof(t_redir) * 1);

	g_cmd->redir_out->fd = 0;
	g_cmd->redir_out->tmp_std = 0;
	g_cmd->redir_out->is_double = 0;
	g_cmd->redir_out->file = (t_list *)malloc(sizeof(t_list) * 1);
	g_cmd->redir_out->file->content = "a.txt";
	g_cmd->redir_out->file->next = (t_list *)malloc(sizeof(t_list) * 1);
	g_cmd->redir_out->file->next->content = "b.txt";
	g_cmd->redir_out->file->next->next = 0;

	g_cmd->redir_in->fd = 0;
	g_cmd->redir_in->tmp_std = 0;
	g_cmd->redir_in->is_double = 0;
	g_cmd->redir_in->file = (t_list *)malloc(sizeof(t_list) * 1);
	g_cmd->redir_in->file->content = "c.txt";
	g_cmd->redir_in->file->next = (t_list *)malloc(sizeof(t_list) * 1);
	g_cmd->redir_in->file->next->content = "d.txt";
	g_cmd->redir_in->file->next->next = 0;

	g_cmd->ispipe = FALSE;
	g_cmd->ispath = FALSE;
	g_cmd->isredir = 1;
	g_cmd->command = (char **)malloc(sizeof(char *) * 3);
	g_cmd->command[0] = "echo";
	g_cmd->command[1] = "hi";
	g_cmd->command[2] = NULL;
	g_cmd->next = NULL;
	return (0);
}

void	loop_prompt(void)
{
	//while (1)
	{
		init_prompt();
		exec_command();
		test_make_cmd_str_to_tokens();

	}
}
void	erase_signal_ascii(void)
{
	ft_printf("\b\b  \b\b\n");
}

void	handle_sigint(int signo)
{
	erase_signal_ascii();
	show_prompt_title();
	return ;
}

void	make_envp_to_t_env(char *envpi)
{
	char	**key_value;

	key_value = ft_split(envpi, "=");
	add_back_new_env(&g_env, new_env(key_value[0], key_value[1]));
	ft_free_arr(key_value, 2);
}

void	init_g_env(char *envp[])
{
	int	i;

	i = -1;
	while (envp[++i])
		make_envp_to_t_env(envp[i]);
}

int		main(int argc, char *argv[], char *envp[])
{
	init_g_env(envp);
	// test_init_g_env(g_env);
	signal(SIGINT, handle_sigint);
	loop_prompt();
	return (0);
}
