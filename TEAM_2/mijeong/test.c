#include <stdio.h>
#include <unistd.h>

void ft_test()
{
    int gval = 10;
    int lval = 20;

    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        gval += 2;
        lval += 2;
    }
    else
    {
        gval -= 2;
        lval -= 2;
    }
    printf("gval: %d\nlval: %d\n", gval, lval);
}

int main(int ac, char **av, char **env)
{
    ft_test();
    char *tmp;
    int i = 0;
    char str[100];
    int result;
    // while (1)
    // {
    //     printf("mijeong >");
    //     while (1)
    //     {
    //         scanf("%s", str);
    //         break;
    //     }
    // }
    char *dir = "/";
    printf("%s\n", getcwd(tmp, __INT32_MAX__));
    result = chdir("/");
    printf("%s\n", getcwd(tmp, __INT32_MAX__));
    printf("%d\n", result);
    
}