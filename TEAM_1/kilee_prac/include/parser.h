#ifndef PARSER_H
# define PARSER_H

typedef int	t_bool;

# define TRUE 1
# define FALSE 0

# define ON 1
# define OFF 2

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define BACKSLASH 92

typedef int t_quotes;

# define CLOSED 1
# define SINGLE_OPEN 2
# define DOUBLE_OPEN 3

typedef struct		s_cmd
{
	char			*cmd_str;
	char			**command;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_quoting
{
	t_bool		escape;
	t_quotes	quotes;
}					t_quoting;

void	parse_cmd_from_input(char *stdin_buf);
t_list	*make_string_to_token_list(char *stdin_buf);
void	make_quotes_in_token_to_literal(t_list **tokens);
t_cmd	*make_token_list_to_cmd_list(t_list **tokens);
int		count_cmd_length(char *ptr);
void	change_quoting(t_quoting *quoting, char	c); // quoting의 맴버인 quote 상태를 현재 문자와 비교하여 변경.
void	init_quoting(t_quoting *quoting);
void	change_escape_status(t_quoting *quoting, char c);
void	change_quotes_status(t_quoting *quoting, char c);

#endif
