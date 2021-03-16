/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:32:39 by kilee             #+#    #+#             */
/*   Updated: 2021/03/04 18:16:15 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_strnstr(const char *target, const char *src,
								size_t target_len);
int					ft_intlen(long long	num);
int					ft_isdigit(int c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_putstr_fd(char *s, int fd);
int					ft_putstr(char *str);
int					ft_signifi_figure(long long num);
t_list				*ft_lstnew(void *content);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_uitoa_base(unsigned int value, char *base);
t_list				*ft_lstlast(t_list *lst);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_ultoa(unsigned long long n);
char				*ft_itoa_base(int value, char *base);
double				ft_pow(double base, int exponent);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstclear(t_list **lst, void (*del)(void*));
char				*ft_ltoa(long long n);
void				ft_lstiter(t_list *lst, void (*f)(void *));
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isascii(int c);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
int					ft_isprint(int c);
void				ft_putendl_fd(char *s, int fd);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
int					ft_lstsize(t_list *lst);
int					ft_toupper(int c);
char				*ft_strndup(const char *s, size_t n);
void				ft_free_arr(char **s, int i);
char				**ft_split(char const *s, const char *set);
void				ft_lstadd_front(t_list **lst, t_list *new);
char				*ft_strrchr(const char *s, int c);
int					ft_isalpha(int c);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_ltoa_base(long long value, char *base);
char				*ft_strchr_only(const char *s, int c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strndup(const char *s1, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_needle(const char *s1, const char *needle, int n_point);
int					ft_dot_move(double i);
char				*ft_join_dotmove(const char *dst, int dot_move);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_ultoa_base(unsigned long long value, char *base);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_uitoa(unsigned int n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
char				*ft_itoa(int n);
int					ft_tolower(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_putchar(char c);

#endif
