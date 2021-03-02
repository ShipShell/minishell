#include <stdio.h>
#include "./libft/libft.h"

int main()
{
	int	i;
	pid_t	pid;
	int	status;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
		printf("자식: %d\n", i);
		i++;
	}
	else
	{
		wait(&status);
		printf("부모: %d\n", i);
	}

	return (0);
}
