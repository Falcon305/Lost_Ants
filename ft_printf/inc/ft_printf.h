/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:04:12 by yidabdes          #+#    #+#             */
/*   Updated: 2020/01/10 19:41:32 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# include "../../libft/libft.h"

# define I(nbr)  nbr - '0'
# define C(nbr) (nbr % 10) + '0'

typedef struct	s_format
{
	int		padding;
	int		leftjustify;
	int		sign;
	int		hash;
	int		space;
	int		width;
	int		isprecised;
	int		precision;
	char	modifer;
	char	specifier;
}				t_format;

typedef struct	s_point
{
	int n1;
	int	n2;
}				t_point;

typedef struct	s_man
{
	char	*nbr;
	char	*man;
	int		exp;
	int		pos;
}				t_man;

typedef struct	s_mult
{
	t_point	len;
	t_point	i;
	int		m;
	int		carry;
	t_point nbr;
}				t_mult;

typedef union	u_float
{
	double		f;
	struct		s_comp
	{
		unsigned long int	mantissa	: 52;
		unsigned long int	exponent	: 11;
		unsigned int		sign		: 1;
	}			t_comp;
}				t_float;

typedef union	u_long_float
{
	long double	f;
	struct		s_lcomp
	{
		unsigned long int	mantissa	: 63;
		unsigned int		int_part	: 1;
		unsigned long int	exponent	: 15;
		unsigned int		sign		: 1;
	}			t_comp;
}				t_long_float;

t_format		ft_get_format(char *str);
int				ft_printf(const char *format, ...);
int				ft_format(char *str, va_list args);
int				ft_print_params(va_list args, t_format format);

void			ft_prefixfixer(char *str);
void			ft_initialise(t_format *format);
void			ft_get_flags(char *str, t_format *f);
void			ft_get_width(char *str, t_format *format);
void			ft_get_padding(char *str, t_format *format);
void			ft_get_modifier(char *str, t_format *format);
void			ft_get_precision(char *str, t_format *format);

int				is_specifier(char c);
int				ft_itoa_base_count(unsigned long int nb, unsigned int base);
char			*ft_itoa_base(unsigned long int nb, unsigned int base);

char			*ft_fix_sign(char *number);
char			*ft_fix_space(char *number);
char			*ft_sign(char *number, t_format format);
int				ft_print_int(long long int nbr, t_format format);
char			*ft_precise_int(char *number, long long int nbr,
				t_format format);

char			*ft_precise_hex(char *number, int precision);
char			*ft_resize_hex(char *number, int width, t_format format);
void			ft_cptoend(char *src, char *dest, int slen, int dlen);
void			ft_cptostart(char *src, char *dest, int slen);

int				ft_convert_id(va_list args, t_format format);
int				ft_print_char(va_list args, t_format format);
int				ft_convert_oux(va_list args, t_format format);
int				ft_print_string(va_list args, t_format format);
int				ft_print_pointer(va_list args, t_format format);

void			ft_fix_prefix(char *str);
int				ft_printhex_getlen(char *str);
int				ft_print_hexa(unsigned long long int nbr, t_format format);
char			*ft_setup_hex(unsigned long long int nbr, t_format format);

int				ft_print_octal(unsigned long long int nbr, t_format format);
char			*ft_setup_octal(unsigned long long int nbr, t_format format);
char			*ft_add_prefix_o(char *str);

int				ft_print_unsigned(unsigned long long int nbr, t_format format);
char			*ft_setup_unsigned(unsigned long long int nbr, t_format format);

char			*ft_add_prefix(char *str, int len);
char			*ft_resize(int width, char zeropad);
char			*ft_precise(char *str, int precision);
char			*ft_str_toupper(char *str, char specifer);
char			*ft_reform(char *src, char*dest, int position);
char			*ft_putatstart(char *src, char *dest, int lsrc, int ldest);
char			*ft_putatend(char *src, char *dest, int lsrc, int ldest);

char			*add(char *nbr1, char *nbr2);
char			*multiply(char *nbr1, char *nbr2);
char			*ft_power(char *nbr, int pow);
int				ft_swap_rev(char **str1, char **str2, t_point *l);
int				ft_swap(char **str1, char **str2, t_point *l);
char			*ft_rm_zeros(char *res);
int				add_zeros(t_man *man, t_format format);

void			ft_double_print(t_float f, t_man *m, t_format format);
void			ft_ldouble_print(t_long_float f, t_man *m, t_format format);
void			ft_fix_float(t_man *man, t_format format);
void			ft_rounding(t_man *m, t_format *f, int exp_pow, int l);

int				ft_print_f(double nbr, t_format format);
int				ft_print_lf(long double nbr, t_format format);
int				ft_convert_double(va_list args, t_format format);
int				add_zeros(t_man *man, t_format format);
void			ft_print_re(char *ret, int *len);

#endif
