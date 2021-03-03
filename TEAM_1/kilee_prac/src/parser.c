#include "minishell.h"

//STEP1 STR to token
t_bool	need_to_cut_token(char *ptr, char *opend_quote, t_bool *escape_on)
{
	if (ft_strchr(" \t\124\49", *ptr) && *opend_quote == QUOTE_CLOSE && *escape_on == FALSE)
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
			*opend_quote = QUOTE_CLOSE;
	}
}

void	set_escape_status(char *ptr, char *opend_quote, t_bool *escape_on)
{
	if (*ptr == '\\' && *opend_quote == QUOTE_CLOSE)
		*escape_on = (*escape_on == TRUE) ? FALSE : TRUE;
}

int		count_token_length(char *ptr)
{
	t_bool	escape_on;
	char	opend_quote;
	int		len;

	escape_on = FALSE;
	opend_quote = QUOTE_CLOSE;
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
	while (ft_strchr(" \t", **ptr) != 0)
		(*ptr)++;
}

t_list	*make_string_to_token_list(char *stdin_buf)
{
	int		len;
	char	opend_quote;
	t_list	*token;
	char	*token_str;

	len = 0;
	opend_quote = QUOTE_CLOSE;
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
// 각 토큰
void	make_quotes_in_token_to_literal(t_list **tokens)
{

}

t_cmd	*make_token_list_to_cmd_list(t_list **tokens);
