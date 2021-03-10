#include "minishell.h"

t_bool	have_syntax_error(char *stdin_buf)
{
	char	*error_char;

	error_char = NULL;
	if (too_many_semicolon(stdin_buf, &error_char)
		|| too_many_right_redirection(stdin_buf, &error_char)
		|| too_many_pipe(stdin_buf, &error_char)
		|| too_many_left_redirection(stdin_buf, &error_char))
	{
		g_exit_code = syntax_error(error_char, 258);
		free(error_char);
		return (TRUE);
	}
	return (FALSE);
}

int		syntax_error(char *error_char, int err_num)
{
	ft_putstr("minishell: syntax error near unexpected token `");
	ft_putstr(error_char);
	ft_putstr("\'\n");
	return (err_num);
}

t_bool	too_many_semicolon(char *stdin_buf, char **error_char)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == ';')
			++count;
		else
			count = 0;
		if (count >= 2)
		{
			*error_char = ft_strdup(";;");
			return (TRUE);
		}
		++stdin_buf;
	}
	return (FALSE);
}

t_bool	too_many_right_redirection(char *stdin_buf, char **error_char)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == '>')
			++count;
		else
			count = 0;
		if (count == 3 && *(stdin_buf + 1) != '>')
		{
			*error_char = ft_strdup(">");
			return (TRUE);
		}
		if (count >= 4)
		{
			*error_char = ft_strdup(">>");
			return (TRUE);
		}
		++stdin_buf;
	}
	return (FALSE);
}

t_bool	too_many_left_redirection(char *stdin_buf, char **error_char)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == '<')
			++count;
		else
			count = 0;
		if (count == 3 && *(stdin_buf + 1) != '<')
		{
			*error_char = ft_strdup("<");
			return (TRUE);
		}
		if (count >= 4)
		{
			*error_char = ft_strdup("<<");
			return (TRUE);
		}
		++stdin_buf;
	}
	return (FALSE);
}

t_bool	too_many_pipe(char *stdin_buf, char **error_char)
{
	int		count;

	count = 0;
	while (*stdin_buf)
	{
		if (*stdin_buf == '|')
			++count;
		else
			count = 0;
		if (count == 3 && *(stdin_buf + 1) != '|')
		{
			*error_char = ft_strdup("|");
			return (TRUE);
		}
		if (count >= 4)
		{
			*error_char = ft_strdup("||");
			return (TRUE);
		}
		++stdin_buf;
	}
	return (FALSE);
}

// t_bool	start_with_unexpected_token(void)
// {
// 	char	*error_char;

// 	error_char = NULL;
// 	if (unexpected_semicolon(&error_char))
// 	{
// 		g_exit_code = syntax_error(error_char, 258);
// 		free(error_char);
// 		return (TRUE);
// 	}
// 	else if (unexpected_pipe(&error_char))
// 	{
// 		g_exit_code = syntax_error(error_char, 258);
// 		free(error_char);
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }

// t_bool	unexpected_semicolon(char **error_char)
// {
// 	t_cmd	*cmd;
// 	int		count;

// 	cmd = g_cmd;
// 	count = 0;
// 	while (cmd)
// 	{
// 		if (**cmd->command == ';')
// 			++count;
// 		else if (count == 1)
// 		{
// 			*error_char = ft_strdup(";");
// 		printf("%d\n", count);
// 			return (TRUE);
// 		}
// 		else
// 			count = 0;
// 		if (count >= 2)
// 		{
// 			*error_char = ft_strdup(";;");
// 			return (TRUE);
// 		}
// 		cmd = cmd->next;
// 	}
// 	return (FALSE);
// }

// t_bool	unexpected_pipe(char **error_char)
// {
// 	t_cmd	*cmd;
// 	int		count;

// 	cmd = g_cmd;
// 	count = 0;
// 	while (cmd)
// 	{
// 		if (**cmd->command == '|')
// 			++count;
// 		else if (count == 1)
// 		{
// 			*error_char = ft_strdup("|");
// 			return (TRUE);
// 		}
// 		else
// 			count = 0;
// 		if (count >= 2)
// 		{
// 			*error_char = ft_strdup("||");
// 			return (TRUE);
// 		}
// 		cmd = cmd->next;
// 	}
// 	return (FALSE);
// }
