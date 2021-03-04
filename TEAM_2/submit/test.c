#include <stdio.h>
#include "libft.h"

int main()
{

//	wait함수 테스트
// 	int	i;
// 	pid_t	pid;
// 	int	status;

// 	i = 0;
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		printf("자식: %d\n", i);
// 		i++;
// 	}
// 	else
// 	{
// 		wait(&status);
// 		printf("부모: %d\n", i);
// 	}
// split에서 나누는거 확인하는 테스트
	// char **dpch;

	// dpch = ft_split("test", '=');
	// printf("1:%s\n2:%s\n", dpch[0], dpch[1]);
	write(2, "hello", 5);
	return (0);
}
