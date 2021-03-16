/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:44:46 by kilee             #+#    #+#             */
/*   Updated: 2021/03/11 15:45:17 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_cmd_str_to_tokens(void)
{
	int			len;
	t_cmd		*current_cmd;
	char		*current_ptr;
	int			i;

	current_cmd = g_cmd;
	while (current_cmd)
	{
		malloc_commands_room(current_cmd);
		current_ptr = current_cmd->cmd_str;
		i = 0;
		len = 0;
		while (*current_ptr)
		{
			skip_seperator_at_first(&current_ptr);
			len = count_token_length(current_ptr);
			current_cmd->command[i++] = ft_strndup(current_ptr, len);
			current_ptr += len;
		}
		current_cmd->ispath = 0;
		current_cmd = current_cmd->next;
	}
}

void	malloc_commands_room(t_cmd *cmd)
{
	int	token_amount;

	token_amount = count_amount_of_tokens(cmd->cmd_str);
	cmd->command = (char **)malloc(sizeof(char *) * (token_amount + 1));
	if (cmd->command == NULL)
		exit(EXIT_FAILURE);
	(cmd->command)[token_amount] = NULL;
}

int		count_amount_of_tokens(char *cmd_str)
{
	int			amount;
	int			len;

	len = 0;
	amount = 0;
	while (*cmd_str)
	{
		skip_seperator_at_first(&cmd_str);
		len = count_token_length(cmd_str);
		cmd_str += len;
		++amount;
	}
	return (amount);
}

t_bool	need_to_cut_token(t_quoting *quoting, char c)
{
	if (ft_strchr(" \t;|><", c) && quoting->escape == OFF
		&& quoting->quotes == CLOSED)
		return (TRUE);
	return (FALSE);
}

int		count_token_length(char *ptr)
{
	t_quoting	quoting;
	int			len;
	t_bool		need_to_cut;

	init_quoting(&quoting);
	len = 0;
	while (ptr[len])
	{
		need_to_cut = need_to_cut_token(&quoting, ptr[len]);
		change_quoting(&quoting, ptr[len]);
		if (need_to_cut)
		{
			if (len == 0 && ft_strchr("|;><", ptr[len]))
				++len;
			return (len);
		}
		++len;
	}
	return (len);
}
