#ifndef PARSER_H
# define PARSER_H

typedef int t_bool;

# define TRUE 1
# define FALSE 0

# define SINGLE_QOUTE_OPEN 1
# define DOUBLE_QOUTE_OPEN 2
# define QUOTE_CLOSE 0

typedef struct		s_cmd
{
	char			**command;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct	s_cutting_status
{
	t_bool	ready_to_cut;
	int		quote_status;
}				t_cutting_status;

typedef struct	s_quote_status
{
	int		quote_open;
	t_bool	escape_on;
}				t_quote_status;

void	parse_cmd_from_input(char **stdin_buf);
t_list	*make_string_to_token_list(char *stdin_buf);
void	make_quotes_in_token_to_literal(t_list **tokens);
t_cmd	*make_token_list_to_cmd_list(t_list **tokens);

#endif
