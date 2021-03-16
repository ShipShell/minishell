/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:42:30 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/11/25 14:01:00 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef SPECIFIER
#  define SPECIFIER "cspdiouxXnfge%"
# endif

# ifndef DIOUXX
#  define DIOUXX "diouxX"
# endif

# ifndef FEGP
#  define FEGP "feg%"
# endif

# ifndef SIGNED
#  define SIGNED "difeg"
# endif

# ifndef UNSIGNED
#  define UNSIGNED "oxX"
# endif

# ifndef LENGTH
#  define LENGTH "hl"
# endif

# ifndef HEX
#  define HEX "0123456789abcdef"
# endif

# ifndef OCTAL
#  define OCTAL "01234567"
# endif

typedef struct			s_conv
{
	va_list				arg_point;
	char				*data;
	int					f_minus;
	int					f_plus;
	int					f_zero;
	int					f_space;
	int					f_num_sign;
	int					precision;
	int					width;
	int					length;
	int					conv_len;
	int					print_size;
	char				specifier;
}						t_conv;

typedef union			u_double
{
	struct
	{
		unsigned long	frac_bit : 52;
		unsigned int	exp_bit : 11;
		unsigned int	sign_bit : 1;
	}					s_bit;
	double				num;
}						t_double;

typedef struct			s_dnum
{
	t_double			num;
	unsigned long long	figure;
	char				*num_str;
	int					precision;
	int					exponent;
	int					is_g;
	char				num_sign;
	char				specifier;
}						t_dnum;

int						ft_nan_check(t_dnum *dnum);
int						ft_bank_check(t_dnum temp,
										unsigned long long round_devide);
int						ft_up_check(t_dnum temp, long long devide);
int						ft_round_figure(t_dnum *dnum, int up,
										long long devide, int use_digit);
int						ft_round_up(t_dnum *dnum);
int						ft_get_data(t_conv *conv);
int						ft_get_data_char(t_conv *conv);
int						ft_get_data_int(t_conv *conv);
int						ft_get_data_unsigned_int(t_conv *conv);
int						ft_get_data_str(t_conv *conv);
int						ft_precision_zero_check(t_conv *conv, int len);
int						ft_precision_diouxx(t_conv *conv);
int						ft_precision_string(t_conv *conv);
int						ft_precision_pointer(t_conv *conv);
int						ft_precision_apply(t_conv *conv);
int						ft_printf(const char *format, ...);
int						ft_print_choice(t_conv *conv, const char **format);
int						ft_parse(const char *format, t_conv *conv);
int						ft_trans(t_conv *conv);
int						ft_align_default(t_conv *conv, int len);
int						ft_align_minus(t_conv *conv, int len);
int						ft_align_zero(t_conv *conv, int len);
int						ft_align(t_conv *conv);
int						ft_plus(t_conv *conv);
int						ft_space(t_conv *conv);
int						ft_number_sign(t_conv *conv);
int						ft_dtoa_get_exponent(t_dnum *dnum);
int						ft_dtoa_get_figure(t_dnum *dnum);
int						ft_spec_g_check(t_dnum *dnum);
int						ft_spec_g_convert(t_dnum *dnum);
int						ft_get_data_percent(t_conv *conv);
int						ft_get_data_num(t_conv *conv);
int						ft_get_data_pointer(t_conv *conv);
int						ft_get_data_double(t_conv *conv);
void					ft_conv_init(t_conv *conv);
void					ft_conv_print_size_init(t_conv *conv);
int						ft_write_conv(t_conv *conv);
int						ft_star_to_width(t_conv *conv);
int						ft_star_to_precision(t_conv *conv);
int						ft_flag_check(const char *format, t_conv *conv);
int						ft_width_check(const char *format, t_conv *conv);
int						ft_precision_check(const char *format, t_conv *conv);
int						ft_length_check(const char *format, t_conv *conv);
int						ft_specifier_check(const char *format, t_conv *conv);
int						ft_dtoa(t_dnum *dnum);
int						ft_dtoa_zero(t_dnum *dnum);
int						ft_put_zero_back(t_dnum *dnum);
int						ft_put_dot_and_zero(t_dnum *dnum);
int						ft_dtoa_join_sign(t_dnum *dnum);
int						ft_int_length_apply(t_conv *conv, long long num);
int						ft_unsigned_int_x_length_apply(t_conv *conv,
														unsigned long long num);
int						ft_unsigned_int_o_length_apply(t_conv *conv,
														unsigned long long num);
int						ft_unsigned_int_u_length_apply(t_conv *conv,
														unsigned long long num);
int						ft_write_conv(t_conv *conv);
int						ft_join_exp(t_dnum *dnum);
int						ft_num_str_f_exponent_apply(t_dnum *dnum);
int						ft_num_str_e_precision_apply(t_dnum *dnum);
int						ft_get_num_str(t_dnum *dnum);

#endif
