#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int		prompt_show(void)
{
	char	*stdin_buf;
	int		input_byte;

	ft_putstr_fd("shipshell$ ", 1);
	get_next_line(0, &stdin_buf);
	// if (ft_strncmp(stdin_buf, "exit", 4) == 0)
	// 	exit(0);
	ft_putstr_fd(stdin_buf, 1);
	write(1, "\n", 1);
	return (0);
}

void	prompt_loop(void)
{
	while(1)
		prompt_show();
}

void	handle_sigint(int signo)
{
	printf("\b\b  \b\b\n");
	ft_putstr_fd("shipshell$ ", 1);
		return ;
}

int		main(int argc, char *argv[], char *envp[])
{
	signal(SIGINT, handle_sigint);
	prompt_loop();
	return (0);
}
