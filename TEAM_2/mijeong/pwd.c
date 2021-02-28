#include "exec.h"

// 출력만 한다. 환경변수나 에러처리를 하지 않았다.
int ft_pwd(t_data *data)
{
    char    *pwd;

    if (getcwd(pwd, 1000))
        return (-1);
    ft_printf("%s", pwd);
    free(pwd);
    return (0);
}