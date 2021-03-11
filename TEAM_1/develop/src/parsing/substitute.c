#include "minishell.h"

void	substitute_command(t_cmd *cmd)
{
	int		i;
	char	*substituted_token;
	char	**command;

	command = cmd->command;
	i = 0;
	while(command[i])
	{
		if (is_pipe_or_semicolon(command[i]))
		{
			change_flag(cmd, &command[i]);
			break;
		}
		substituted_token = substitute_token(command[i]);
		free(command[i]);
		command[i] = substituted_token;
		++i;
	}
}

void	substitute_redir(t_cmd *cmd)
{
	t_list	*file;

	if (cmd->isredir == FALSE)
		return ;
	if (cmd->redir_in)
	{
		file = cmd->redir_in->file;
		substitute_redir_file_list(file);
	}
	if (cmd->redir_out)
	{
		file = cmd->redir_out->file;
		substitute_redir_file_list(file);
	}
}

void	substitute_redir_file_list(t_list *file)
{
	char	*substituted_file;

	while (file)
	{
		substituted_file = substitute_token(file->content);
		free(file->content);
		file->content = substituted_file;
		file = file->next;
	}
}

t_bool	is_pipe_or_semicolon(char *token)
{
	if (*token == '|' || *token == ';' || *token == '\0')
		return (TRUE);
	return (FALSE);
}

void	change_flag(t_cmd *cmd, char **token)
{
	if (**token == '|')
		cmd->ispipe = TRUE;
	free(*token);
	*token = NULL;
}
char	*substitute_token(char *token)
{
	char		*buffer;
	char		*buffer_start;
	int			len;
	t_quoting	quoting;

	buffer = ft_calloc(BUFFER_MAX, sizeof(char));
	if (buffer == NULL)
		exit (1);
	init_quoting(&quoting);
	buffer_start = buffer;
	len = 0;
	while(*token)
	{
		len = push_char_to_buffer(&buffer, token, &quoting);
		change_quoting(&quoting, *token);
		token += len;
	}
	return (buffer_start);
}

int		push_char_to_buffer(char **buffer, char *token, t_quoting *quoting)
{
	int		action;

	action = check_substitute_action(quoting, *token);
	if (action == SUB_SPECIAL) //  - sigavold 나주엥 막아야함.
		return (substitute_special_char(buffer, token));
	else if (action == SUB_LITERAL) // action = SUB_LITERAL - sigavold 4096이상 나주엥 막아야함.
	{
		**buffer = *token;
		++*buffer;
	}
	return (1);
}

int		check_substitute_action(t_quoting *quoting, char c)
{

	if (ft_strchr("$~", c) && quoting->escape == OFF
		&& quoting->quotes != SINGLE_OPEN)
		return (SUB_SPECIAL);
	else if (c == SINGLE_QUOTE && quoting->quotes != DOUBLE_OPEN)
		return (SUB_SKIP);
	else if (c == DOUBLE_QUOTE && quoting->quotes != SINGLE_OPEN)
		return (SUB_SKIP);
	else if (c == BACKSLASH && quoting->escape == OFF)
		return (SUB_SKIP);
	else
		return (SUB_LITERAL);
}

int		substitute_special_char(char **buffer, char *token)
{
	int		len;
	char	*key;
	char	*value;

	len = 1;
	if (token[0] == '$')
	{
		if (token[len] == '?')
		{
			push_exit_code_to_buffer(buffer);
			return (2);
		}
		while(ft_isalpha(token[len]) || token[len] == '_')
			++len;
		if (len == 1)
		{
			**buffer = *token;
			++*buffer;
			return (1);
		}
		key = ft_strndup(&token[1], len - 1);
		value = find_value_match_with(key);
		push_value_to_buffer(value, buffer);
		free(key);
	}
	else if (token[0] == '~')
	{
		value = find_value_match_with("HOME");
		push_value_to_buffer(value, buffer);
	}
	return (len);
}

void	push_exit_code_to_buffer(char **buffer)
{
	char	*exit_code_str;
	int		i;

	exit_code_str = ft_itoa(g_exit_code);
	i = -1;
	while (exit_code_str[++i])
	{
		**buffer = exit_code_str[i];
		++*buffer;
	}
	free(exit_code_str);
	exit_code_str = NULL;
}

void	push_value_to_buffer(char *value, char **buffer)
{
	int	i;

	if (value == NULL)
		return ;
	i = 0;
	while (*value)
	{
		**buffer = *value;
		++*buffer;
		++value;
	}
}

char	*find_value_match_with(char *key)
{
	t_env	*current_env;

	current_env = g_env;
	while (current_env)
	{
		if (ft_strcmp(current_env->key, key) == 0)
			break ;
		current_env = current_env->next;
	}
	if (current_env == NULL)
		return (NULL);
	else
		return (current_env->val);
}
