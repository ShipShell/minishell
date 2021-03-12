#ifndef TESTER_H
# define TESTER_H

#include "structures.h"

void	test_change_quoting(t_quoting quoting);
void	test_save_redir_list(t_list *redir_list);
void	test_save_tmp_token(t_list *tmp);
void	test_list_to_token(char **token);
void	test_check_whether_replace(int replace_check);

#endif