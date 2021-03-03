#include "minishell.h"

//STEP1 STR to token
t_bool	need_to_cut_token(char *ptr, char *opend_quote, t_bool *escape_on)
{
	if (ft_strchr(" \t", *ptr) && *opend_quote == CLOSED && *escape_on == FALSE)
		return (TRUE);
	return (FALSE);
}

void	set_quote_status(char *ptr, char *opend_quote)
{
	if (*ptr == '\'' || *ptr == '\"')
	{
		if (*opend_quote == '\0')
			*opend_quote = *ptr;
		else if (*ptr == *opend_quote)
			*opend_quote = CLOSED;
	}
}

void	set_escape_status(char *ptr, char *opend_quote, t_bool *escape_on)
{
	if (*ptr == '\\' && *opend_quote == CLOSED)
		*escape_on = (*escape_on == TRUE) ? FALSE : TRUE;
}

int		count_token_length(char *ptr)
{
	t_bool	escape_on;
	char	opend_quote;
	int		len;

	escape_on = FALSE;
	opend_quote = CLOSED;
	len = 0;
	while (ptr[len])
	{
		set_quote_status(&ptr[len], &opend_quote);
		set_escape_status(&ptr[len], &opend_quote, &escape_on);
		if (need_to_cut_token(&ptr[len], &opend_quote, &escape_on))
			return (len);
		++len;
	}
	return (len);
}

void	skip_seperator_at_first(char **ptr)
{
	while (**ptr && ft_strchr(" \t|;", **ptr) != 0)
		(*ptr)++;
}

t_list	*make_string_to_token_list(char *stdin_buf)
{
	int		len;
	char	opend_quote;
	t_list	*token;
	char	*token_str;

	len = 0;
	opend_quote = CLOSED;
	token = NULL;
	while (*stdin_buf)
	{
		skip_seperator_at_first(&stdin_buf);
		len = count_token_length(stdin_buf);
		token_str = ft_strndup(stdin_buf, len);
		ft_lstadd_back(&token, ft_lstnew(token_str));
		stdin_buf += len;
	}
	test_make_string_to_token_list(token);
	return (token);
}

//STEP2 토큰 내의 special 치환,
//1. 앞에서부터 문자 체크, single_quote 오픈 / double_quote 오픈 체크
//2. escape on off 체크, $ 만나면 변수 치환 체크
//3. i 쭉쭉가다가, 특수 케이스 만나거나 토큰 종료되면 join
//4. | 나 ; 만나면 토큰 새로 만들기.
// move
void	make_quotes_in_token_to_literal(t_list **tokens)
{

}

t_cmd	*make_token_list_to_cmd_list(t_list **tokens);

//STEP1. cmd_str ; | 기준으로 쪼개기

t_bool	need_to_cut_command(t_quoting *quoting, char c)
{
	if ((c == ';' || c == '|') && quoting->escape == OFF
		&& quoting->quotes == CLOSED)
	{
		// printf("escape:%d quotes %d, c : %c\n", quoting->escape, quoting->quotes, c);
		return (TRUE);
	}
	return (FALSE);
}

void	parse_cmd_from_input(char *stdin_buf)
{
	int		len;
	char	*cmd_str;

	len = 0;
	while (*stdin_buf)
	{
		skip_seperator_at_first(&stdin_buf);
		len = count_cmd_length(stdin_buf);
		cmd_str = ft_strndup(stdin_buf, len);
		add_back_new_cmd(&g_cmd, new_cmd(cmd_str));
		stdin_buf += len;
	}
}

int		count_cmd_length(char *ptr)
{
	t_quoting	quoting;
	int			len;
	t_bool		need_to_cut;

	init_quoting(&quoting);
	len = 0;
	while (ptr[len])
	{
		need_to_cut = need_to_cut_command(&quoting, ptr[len]);
		change_quoting(&quoting, ptr[len]);
		if (need_to_cut)
			return (len);
		++len;
	}
	return (len);
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

void	init_quoting(t_quoting *quoting)
{
	quoting->quotes = CLOSED;
	quoting->escape = OFF;
}
