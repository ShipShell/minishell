#include "minishell.h"

int 	check_whether_replace(char c, t_quoting quoting)
{
	int		replace_check;

	change_quoting(c, &quoting);
	if (c == '$' && quoting.quotes != SINGLE_OPEN && quoting.old_escape == OFF)
		replace_check = DOLLAR_ON;	
	else if (c == '~' && quoting.quotes != SINGLE_OPEN && quoting.old_escape == OFF)
		replace_check = WAVE_ON;
	else
		replace_check = NOT_TO_REPLACE;
	return (replace_check);
}