#include "exec.h"
#include "structures.h"

// 출력만 한다. 환경변수나 에러처리를 하지 않았다.
int	ft_pwd(t_cmd *cmd)
{
	char	pwd[MAX_BUFF];

	if (!getcwd(pwd, MAX_BUFF))
		return (-1);
	ft_printf("%s\n", pwd);
	return (0);
}
