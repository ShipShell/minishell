#include "minishell.h"

void	parse_and_split_from_input(char *stdin_buf)
{
	parse_cmd_from_input(stdin_buf);
	make_cmd_str_to_tokens();
}

//STEP1. cmd_str ; | 기준으로 쪼개기
void	parse_cmd_from_input(char *stdin_buf)
{
	int		len;
	char	*cmd_str;

	len = 0;
	while (*stdin_buf)
	{
		skip_seperator_at_first(&stdin_buf);
		len = count_cmd_length(stdin_buf);
		if (len == 0)
			break;
		cmd_str = ft_strndup(stdin_buf, len);
		add_back_new_cmd(&g_cmd, new_cmd(cmd_str));
		stdin_buf += len;
	}
}

void	skip_seperator_at_first(char **ptr)
{
	while (**ptr && ft_strchr(" \t", **ptr) != 0)
		(*ptr)++;
}

int		count_cmd_length(char *ptr)
{
	t_quoting	quoting;
	int			len;
	t_bool		need_to_cut;

	init_quoting(&quoting);
	len = 0;
	while (*ptr)
	{
		++len;
		need_to_cut = need_to_cut_command(&quoting, *ptr);
		change_quoting(&quoting, *ptr);
		if (need_to_cut)
			return (len);
		ptr++;
	}
	return (len);
}

void	init_quoting(t_quoting *quoting)
{
	quoting->quotes = CLOSED;
	quoting->escape = OFF;
}

t_bool	need_to_cut_command(t_quoting *quoting, char c)
{
	if ((c == ';' || c == '|') && quoting->escape == OFF
		&& quoting->quotes == CLOSED)
		return (TRUE);
	return (FALSE);
}

//Quoting structure 상태 변화 함수.
void	change_quoting(t_quoting *quoting, char	c)
{
	if (c == BACKSLASH)
		change_escape_status(quoting, c);
	else if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE)
		change_quotes_status(quoting, c);
	else if (quoting->escape == ON)
		quoting->escape = OFF;
}

void	change_escape_status(t_quoting *quoting, char c)
{
	if (quoting->quotes != SINGLE_OPEN)
	{
		if (quoting->escape == ON)
			quoting->escape = OFF;
		else
			quoting->escape = ON;
	}
}

void	change_quotes_status(t_quoting *quoting, char c)
{
	if (c == SINGLE_QUOTE && quoting->escape == OFF)
	{
		if (quoting->quotes == CLOSED)
			quoting->quotes = SINGLE_OPEN;
		else if (quoting->quotes == SINGLE_OPEN)
			quoting->quotes = CLOSED;
	}
	else if (c == DOUBLE_QUOTE && quoting->escape == OFF)
	{
		if (quoting->quotes == CLOSED)
			quoting->quotes = DOUBLE_OPEN;
		else if (quoting->quotes == DOUBLE_OPEN)
			quoting->quotes = CLOSED;
	}
}


//STEP2 char *cmd_str -> char **cmd 토큰화 단계
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
		while(*current_ptr)
		{
			skip_seperator_at_first(&current_ptr);
			len = count_token_length(current_ptr);
			current_cmd->command[i++] = ft_strndup(current_ptr, len);
			//printf("cmd[%d] : %s\n", i - 1, g_cmd->command[i - 1]);
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

int		count_amount_of_tokens(char	*cmd_str)
{
	int			amount;
	int			len;

	len = 0;
	amount = 0;
	while(*cmd_str)
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
	// if (*ptr == '|' || *ptr == ';')
	// 	return (1);
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
