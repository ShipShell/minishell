#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include "parser.h"

void	test_init_g_env(t_env *envs);
void	test_make_cmd_str_to_tokens(void);
void	test_change_quoting(void);
void	test_parse_cmd_from_input(void);

#endif
