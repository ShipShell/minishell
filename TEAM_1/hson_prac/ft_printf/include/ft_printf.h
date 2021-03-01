/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hson <hson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:10:24 by hson              #+#    #+#             */
/*   Updated: 2020/11/17 13:21:19 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../srcs/libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct	s_format
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			sign;
}				t_format;

int				ft_printf(const char *format, ...);
int				parsing_format(va_list ap, const char *format);
int				fill_format(va_list ap, t_format *form,
							const char *format, int i);
void			is_wd_or_prc(va_list ap, t_format *form, const char c);
int				print_format(va_list ap, t_format *form);

int				print_char(int c, t_format *form);
int				put_width(char c, int width, int minus, int zero);

int				print_str(char *str, t_format *form);
char			*put_string(char *str, int prec, int str_len);
int				put_width_str(char *save, t_format *form);

int				print_integer(long long nbr, t_format *form);
char			*put_integer(long long nbt, int prec, int nbr_len);

int				print_unsigned(unsigned long long nbr, t_format *form);
char			*get_nbr_base(unsigned long long nbr,
							unsigned long long nbr_base, char type);
char			*put_unsigned_prec(char *save, char *nbr_base,
							int len, t_format *form);
char			*put_unsigned(unsigned long long nbr, t_format *form);

void			init_form(t_format *form);
char			*ft_base(int base, char type);
int				ft_baselen(unsigned long long nbr, unsigned long long base);

#endif
