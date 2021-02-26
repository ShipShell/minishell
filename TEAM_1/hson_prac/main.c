#include <stdio.h>

int main()
{
	char buf[10];

	while (1)
	{
		printf("minishell>");
		while (1)
			scanf("%s", buf);
	}
}