#include "exec.h"

int	ft_pwd(void)
{
	char	pwd[MAX_BUFF];

	if (!getcwd(pwd, MAX_BUFF))
		return (-1);
	ft_printf("%s\n", pwd);
	return (1);
}
