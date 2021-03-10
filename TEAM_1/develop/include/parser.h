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

# define SUB_LITERAL 1
# define SUB_SKIP 2
# define SUB_SPECIAL 3

typedef struct		s_redir
{
	t_list			*file;
	int				fd;
	int				tmp_std;
	t_bool			is_double;
}					t_redir;

typedef struct		s_cmd
{
	t_redir			*redir_in;
	t_redir			*redir_out;
	char			*cmd_str;
	char			**command;
	t_bool			ispath;
	t_bool			ispipe;
	t_bool			isredir;
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

//redir
void	change_redir_status(t_cmd *cmd);
void	check_cmd_list_redirection(void);
void	add_redir(t_cmd *cmd, int i, int in_count, int out_count);
void	add_out_redir(t_cmd *cmd, int i, t_bool isdouble);
void	add_in_redir(t_cmd *cmd, int i, t_bool isdouble);

//substitute.c
void	substitute_command(t_cmd *cmd);
char	*substitute_token(char *token);
int		push_char_to_buffer(char **buffer, char *token, t_quoting *quoting);
void	push_exit_code_to_buffer(char **buffer);
int		check_substitute_action(t_quoting *quoting, char c);
int		substitute_special_char(char **buffer, char *token);
void	push_value_to_buffer(char *value, char **buffer);
char	*find_value_match_with(char *key);
t_bool	is_pipe_or_semicolon(char *token);
void	change_flag(t_cmd *cmd, char **token);
void	substitute_redir(t_cmd *cmd);
void	substitute_redir_file_list(t_list *file);

#endif
