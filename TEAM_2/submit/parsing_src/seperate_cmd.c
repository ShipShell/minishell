/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:59:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/02/28 18:43:01 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"

void			seperate_cmdline(char *stdin_buf, t_list *cmd_list)
{
	t_list	*cmdline_list;

	cmdline_list = sep_to_single_command(stdin_buf); // 일단 ;와 |를 기준으로 스트링으로 자르기
	while (cmdline_list != NULL)
	{
		ft_lstadd_back(&cmd_list,
			ft_lstnew(sep_to_token((char *)cmdline_list->content))); // 자른 스트링을 다시 토큰으로 자르기
		cmdline_list = cmdline_list->next;
	}
}

// 일단 ;와 |를 기준으로 스트링으로 자르기
t_list			*sep_to_single_command(char *stdin_buf)
{
	t_list	*cmdline_list;
	char	*cmdline;
	char	cmd_len;

	cmdline_list = NULL;
	while (*stdin_buf != '\0')
	{
		cmd_len = command_len(stdin_buf);
		cmdline = ft_strndup(stdin_buf, cmd_len);
		ft_lstadd_back(&cmdline_list, ft_lstnew(cmdline));
		stdin_buf = stdin_buf + cmd_len;
	}
	return (cmdline_list);
}

int				command_len(char *stdin_buf)
{
	int		len;

	len = 0;
	while (*stdin_buf != '\0')
	{
		++len;
		if (*stdin_buf == ';' || *stdin_buf == '|')
			break ;
		stdin_buf++;
	}
	return (len);
}

static void		test_data(t_data *cmd_set)
{
	printf("COMMAND : %s\n", cmd_set->cmd);
	while (cmd_set->arg != NULL)
	{
		printf("ARGUMENT : %s\n", cmd_set->arg->content);
		cmd_set->arg = cmd_set->arg->next;
	}
	// printf("\n");
	if (cmd_set->seperator == PIPE_LINE)
		printf("SEPERATOR : pipe line\n");
	else if (cmd_set->seperator == SEMI_COLON)
		printf("SEPERATOR : semi colon\n");	
	printf("\n");
}

// 자른 스트링을 다시 토큰으로 자르기

int	check_exec(t_data *data)
{
	if (!ft_strcmp(data->cmd, "env"))
		ft_env(data);
	else if (!ft_strcmp(data->cmd, "cd"))
		ft_cd(data);
	else if (!ft_strcmp(data->cmd, "echo"))
		ft_echo(data);
	else if (!ft_strcmp(data->cmd, "pwd"))
		ft_pwd(data);
	else if (!ft_strcmp(data->cmd, "unset"))
		ft_unset(data);
	else
		return (-1);
	return (0);
}

t_data			*sep_to_token(char *single_cmd)
{
	int		idx;
	char	**token;
	t_list	*arg;
	t_data	*cmd_set;

	arg = NULL;
	idx = 0;
	if (!(cmd_set = (t_data *)malloc(sizeof(t_data))))
		return (0);
	token = ft_split(single_cmd, ' ');
	cmd_set->cmd = token[0];
	while (token[++idx])
		ft_lstadd_back(&arg, ft_lstnew(token[idx]));
	cmd_set->arg = arg;
	check_exec(cmd_set);
	// test_data(cmd_set);
	return (cmd_set);
}