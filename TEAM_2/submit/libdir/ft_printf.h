/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:18:09 by mijeong           #+#    #+#             */
/*   Updated: 2021/03/15 17:26:21 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"

typedef union				u_f
{
	struct
	{
		unsigned long long	frac : 52;
		unsigned long long	ex : 11;
		unsigned long long	s : 1;
	}						s_bit;
	double					d;
}							t_f;

/*
**ft_printf.c
*/
int							ft_printf(const char *str, ...);
int							check_percent(char **str, t_key *key);
void						init_key(t_key *key);
/*
**ft_checking.c
*/
int							check_astro(char **str,
									t_key *key, int *i, int pw_switch);
int							check_flag(char **str, t_key *key);
int							check_width(char **str, t_key *key);
int							check_precision(char **str, t_key *key);
int							check_format(char **str, t_key *key);
/*
**cd_printing.c
*/
int							align_check(int count,
									t_key *key, long long int result);
int							choose_printer(t_key *key);
int							d_printer(t_key *key);
/*
**us_printing.c
*/
int							s_printer(t_key *key);
int							u_align_check(int count, t_key *key,
										unsigned long long int result);
int							u_printer(t_key *key);
void						ft_putunbr_fd(unsigned long long int n, t_key *key);
int							s_align_check(int count, t_key *key);
/*
**xp_printing.c
*/
void						print_hex(unsigned long long n, int ud, t_key *key);
int							p_align_check(int count, t_key *key,
											unsigned long long result);
int							p_printer(t_key *key);
int							x_printer(t_key *key);
int							ux_printer(t_key *key);
/*
**xp_printing2.c
*/
int							x_align_check(int count, t_key *key,
										unsigned long long int result);
/*
**per_printing.c
*/
int							per_printer(t_key *key);
/*
**f_printing.c
*/
int							f_align_check(int count, t_key *key,
												union u_f result);
void						putdecimal(t_key *key,
											union u_f result, int count);
int							f_printer(t_key *key);
int							bankround(int count, union u_f *result,
										long long int *front, t_key *key);
int							bitcheck(union u_f result, t_key *key);
/*
**util.c
*/
int							d_util(t_key *key, long long int result);
int							x_util(t_key *key, int ul_switch,
											unsigned long long int result);
int							f_util(t_key *key, unsigned long sign);
long long int				hl_check(t_key *key, long long int result);
unsigned long long int		uhl_check(t_key *key,
								unsigned long long int result);
/*
**ls_printing.c
*/
int							ls_printer(t_key *key);
/*
**putfunc.c
*/
void						putfunc(char c, t_key *key);
/*
**n_printing.c
*/
int							n_printer(t_key *key);
/*
**bankround2.c
*/
int							bankround_div(union u_f *result,
								long long int *front, t_key *key, int count);
#endif
