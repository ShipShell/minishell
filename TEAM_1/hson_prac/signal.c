#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"

void    print_prompt(void)
{
    write(1, "shell$>", 6);
}

void    sig_handler(int signo, int *i)
{
    if (signo == 2)
    {
        printf("\b\b  \b\b\n");
        print_prompt();
        return ;
    }
    if (signo == 3)
        printf("\b\b  \b\bSIGQUIT 발생\n");
        print_prompt();
    return ;
}

int     main(int ac, char **av, char **env)
{
    char    *line;
    int     i;
    signal(SIGQUIT, (void *)sig_handler);
    signal(SIGINT, (void *)sig_handler);
    while (1)
    {
        print_prompt();
        while(1)
        {
            if (get_next_line(1, &line) == 1)
            {
                write(1, line, sizeof(line));
                write(1, "\n", 1);
                free(line);
                break ;
            }
        }
    }
}















