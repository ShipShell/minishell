/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <minje70@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:04:44 by mijeong           #+#    #+#             */
/*   Updated: 2020/11/06 18:18:25 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_flag
{
	int			minus;
	int			zero;
	int			plus;
	int			space;
	int			pound;
	int			l;
	int			ll;
	int			h;
	int			hh;
}					t_flag;

typedef struct		s_key
{
	t_flag			flag;
	int				width;
	int				precision;
	int				percent;
	char			format;
	long long int	result;
	va_list			ap;
}					t_key;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *ptr, int value, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *destination, const void *source,
								size_t num);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *destination, const void *source,
								size_t num);
void				*ft_memchr(void *ptr, int value, size_t num);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, char *src, size_t size);
char				*ft_strchr(const char *str, int chr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strrchr(char *str, int chr);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *dst, const char *src, size_t len);
int					ft_atoi(const char *cstr);
void				*ft_calloc(size_t elt_count, size_t elt_size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strcmp(char *str1, char *str2);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(long long int n, t_key *key);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
void				*(*f)(void *), void (*del)(void *));

// ft_ printf

#endif
