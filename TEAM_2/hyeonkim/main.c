#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

int j;

void	sig_handler(int signo, int *i)
{
    if (signo == 2)
	{
    	printf("SIGINT 발생\n");
		j = 1;
		return ;
	}
    else if (signo == 3)
    	printf("SIGQUIT 발생\n");
		j = 0;
		return ;
	return ;
}

void	print_prompt(void)
{
	write(1, "shell$", 6);
}

int		main(int ac, char **av, char **env)
{
	char *line;
	int		i;
	int	t;

	signal(SIGQUIT, (void *)sig_handler);
	signal(SIGINT, (void *)sig_handler);
	print_prompt();
	while (1)
	{
		j = 0;
		print_prompt();
		while(1)
		{
			if (j == 1 || get_next_line(0, &line) == 1)
			{
				if (line == 0)
					break ;
				write(1, line, sizeof(line));
				write(1, "\n", 1);
				free(line);
				break ;
			}
		}
	}
}

