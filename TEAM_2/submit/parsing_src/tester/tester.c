#include "tester.h"

void			test_init_quoting(t_quoting *quoting)
{
	quoting->escape = OFF;
	quoting->quotes = CLOSED;
}

void			test_change_quoting(char c, t_quoting *quoting)
{

}

// static char		*tester(int i)
// {
// 	if (i == 1)
// 		return ("ON");
// 	else if (i == 2)
// 		return ("OFF");
// 	else if (i == 3)
// 		return ("CLOSED");
// 	else if (i == 4)
// 		return ("SINGLE_OPEN");
// 	else if (i == 5)
// 		return ("DOUBLE_OPEN");
// }

// while (single_cmd_list != NULL)
// {
// 	printf("single_cmd : %s\n", (char *)(single_cmd_list->content));
// 	single_cmd_list = single_cmd_list->next;
// }
// t_quoting	quoting;
// int			i;
// i = -1;
// init_quoting(&quoting);
// while (str[++i])
// {
	// change_quoting(str[i], &quoting);
	
	// printf(" %c ) quotes : %s / escape : %s / old_escape : %s \n", str[i], 
	// tester(quoting.quotes), tester(quoting.escape), tester(quoting.old_escape));
// }

// while (tokenized_single_cmd_list != NULL)
// {
// 	printf("single_cmd : %s\n", (char *)(tokenized_single_cmd_list->content));
// 	tokenized_single_cmd_list = tokenized_single_cmd_list->next;
// }

int				test_get_token_len(char *str)
{
	int			token_len;
	t_quoting	quoting;

	init_quoting(&quoting);
	token_len = 0;
	while (*str)
	{
		++token_len;
		change_quoting(*str, &quoting);
		if (ft_strchr(";|\t ", *str)
			&& quoting.quotes == CLOSED) // && quoting.old_escape == OFF
			break ;
		str++;
	}
	return (token_len);
}

void			test_tokenize_single_cmd(char *str)
{
	t_cmd		*tokenized;
	int			token_len;
	int			token_count;

	token_count = 0;
	token_len = 0;
	tokenized = (t_cmd *)malloc(sizeof(t_cmd));
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		token_len = test_get_token_len(str);
		str = str + token_len;
		++token_count;
	}
}


// tokenize.c 안의 static char		**split_single_cmd(char *str) 함수 내에 붙여서 사용할 것
// printf("token_count : %d\n", token_count);
// 	i = 0;
// 	while (token[i])
// 	{
// 		printf("token[%d] : %s\n", i, token[i]);
// 		++i;
// 	}
// 	printf("\n");