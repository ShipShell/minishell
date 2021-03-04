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
	int				ispath;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}					t_env;

typedef struct		s_quoting
{
	t_bool		escape;
	t_quotes	quotes;
}					t_quoting;

void	parse_and_split_from_input(char *stdin_buf);

//step1
void	parse_cmd_from_input(char *stdin_buf);
void	skip_seperator_at_first(char **ptr);
int		count_cmd_length(char *ptr);
void	init_quoting(t_quoting *quoting);
t_bool	need_to_cut_command(t_quoting *quoting, char c);
void	change_quoting(t_quoting *quoting, char	c);
void	change_escape_status(t_quoting *quoting, char c);
void	change_quotes_status(t_quoting *quoting, char c);

//step2
void	make_cmd_str_to_tokens(void);
void	malloc_commands_room(t_cmd *cmd);
int		count_amount_of_tokens(char	*cmd_str);
t_bool	need_to_cut_token(t_quoting *quoting, char c);
int		count_token_length(char *ptr);


#endif
