#include <stdio.h>
#include "exec.h"
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
	// char	*str = "test";
	// char	**dstr;
	// int		i;
	

	// dstr = ft_split(str, '=');
	// i = -1;
	// while (dstr[++i])
	// 	printf("%d:%s\n", i, dstr[i]);

	// char *tttt[5];
	// int	i;

	// i = -1;
	// tttt[0] = "hello";
	// // test[0] = 0;
	
	// while (tttt[++i])
	// 	printf("%d: %s\n", i, tttt[i]);

	// redirection 테스트!!!
	// 리스트는 이렇게 만드는게 아니잖니?? 똑바로 좀 하자^^
	t_list	*cmd_list;
	t_list	*redir_list;
	t_cmd	cmd[1];
	t_redir	redir[3];
	char	*token[3];

	t_env	env;

	env.key = "PATH";
	env.value = "/Users/mijeong/.brew/bin:/Users/mijeong/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki";
	g_env = ft_lstnew(&env);

	token[0] = "cat";
	token[1] = 0;
	token[2] = 0;

	cmd_list = ft_lstnew(cmd);

	redir_list = ft_lstnew(redir);
	ft_lstadd_back(&redir_list, ft_lstnew(redir + 1));
	ft_lstadd_back(&redir_list, ft_lstnew(redir + 2));

	((t_cmd *)cmd_list->content)->redir = redir_list;
	((t_cmd *)cmd_list->content)->flag = SEMICOLON;
	((t_cmd *)cmd_list->content)->token = token;

	((t_redir *)redir_list->content)->filename = "a.txt";
	((t_redir *)redir_list->next->content)->filename = "b.txt";
	((t_redir *)redir_list->next->next->content)->filename = "c.txt";
	((t_redir *)redir_list->content)->redir_type = REDIR_OUT;
	((t_redir *)redir_list->next->content)->redir_type = REDIR_IN;
	((t_redir *)redir_list->next->next->content)->redir_type = REDIR_OUT;

	cycle_list(cmd_list);

	return (0);
}
