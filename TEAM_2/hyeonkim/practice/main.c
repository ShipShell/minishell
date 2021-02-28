#include <stdio.h>

int		cmd_len(char *stdin_buf)
{
	int	len;

	len = 0;
	while (*stdin_buf != '\0')
	{
		++len;
		if (*stdin_buf == ';' || *stdin_buf == '|')
			break ;
		stdin_buf++;
	}
	return (len);
}

int		main()
{
	char *str = "a;";

	printf("len : %d\n", cmd_len(str));
}