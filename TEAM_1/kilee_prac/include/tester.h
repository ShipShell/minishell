#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include "parser.h"

void	test_init_g_env(t_env *envs);
void	test_make_string_to_token_list(t_list *tokens);
void	test_change_quoting(void);
void	test_parse_cmd_from_input(void);

#endif
