#include "exec.h"

// exit으로 끝내야할 듯.
int	call_no_home_err()
{
	ft_putstr_fd("shipshell: cd: HOME not set\n", 1);
	g_exit_code = 1;
	return (-1);
}