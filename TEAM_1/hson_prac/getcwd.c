#include <unistd.h>
#include <stdio.h>

int main(int ac, char *av[], char **env)
{
	char	buf[255];
	int		ret;
//	char	*path;
	int 	i;
	// pid_t	pid;

	// pid = fork();

	printf("%s\n", getcwd(buf, 255));
//	path = "~";
	ret = chdir("/");
	printf("%s\nreturn : %d\n", getcwd(buf, 255), ret);
//	execve("/bin/pwd",av,env);
//	execve("/bin/ls",av,env);
	// i = 0;
	// while (env[i])
	// 	printf("%s\n", env[i++]);
	return (1);
}