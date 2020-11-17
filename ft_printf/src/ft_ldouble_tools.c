/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldouble_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 22:40:15 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:47 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fix_lmantissa(char *man)
{
	char	*res;
	int		i;

	i = 63 - ft_strlen(man);
	res = ft_strnew(63);
	res = ft_memset(res, '0', 63);
	if (ft_strlen(man) < 63)
	{
		while (i < 63)
		{
			res[i] = *man;
			man++;
			i++;
		}
	}
	else
		return (man);
	return (res);
}

static void		ft_get_ld(t_man *m, int exp_pow)
{
	int		len;
	t_point	i;
	char	*tmp;

	exp_pow = (exp_pow >= 0) ? 0 : exp_pow;
	i.n2 = ft_strlen(m->nbr) - 1;
	len = (exp_pow >= 0) ? ft_strlen(m->nbr) : (ft_strlen(m->nbr) - exp_pow);
	tmp = ft_strnew(len + 1);
	tmp = ft_memset(tmp, '0', len + 1);
	i.n1 = len;
	m->pos = len + exp_pow - 63;
	while (i.n1 >= 0)
	{
		if (i.n1 == m->pos)
			tmp[i.n1--] = '.';
		if (i.n2 >= 0)
			tmp[i.n1] = m->nbr[i.n2];
		i.n1--;
		i.n2--;
	}
	free(m->nbr);
	m->nbr = tmp;
}

static void		ft_process_ld(t_man *m, int exp_pow)
{
	int	i;

	i = 0;
	m->pos = 1;
	m->man = ft_fix_lmantissa(m->man);
	if (m->exp == 0)
		m->nbr = ft_strdup("0");
	else
		m->nbr = ft_strdup("1");
	while (i < 63)
	{
		m->nbr = multiply(ft_strdup(m->nbr), ft_strdup("10"));
		if (m->man[i] == '1')
			m->nbr = add(m->nbr, ft_power(ft_strdup("5"), (i + 1)));
		i++;
	}
	if (exp_pow < 0)
		m->nbr = multiply(m->nbr, ft_power(ft_strdup("5"), -exp_pow));
	else
		m->nbr = multiply(m->nbr, ft_power(ft_strdup("2"), exp_pow));
	m->nbr = ft_rm_zeros(m->nbr);
}

static void		zero_f(t_man *m, t_format f)
{
	m->nbr = ft_strdup("0.");
	if (f.precision == 0 && f.isprecised)
	{
		free(m->nbr);
		m->nbr = ft_strdup("0");
	}
	else if (!f.isprecised)
	{
		free(m->nbr);
		m->nbr = ft_strdup("0.000000");
	}
	else
		add_zeros(m, f);
}

void			ft_ldouble_print(t_long_float f, t_man *m, t_format format)
{
	int			exp_pow;
	int			zero;

	zero = (f.t_comp.exponent == 0 && f.t_comp.mantissa == 0) ? 0 : 1;
	m->man = ft_itoa_base(f.t_comp.mantissa, 2);
	m->exp = f.t_comp.exponent;
	exp_pow = m->exp - 16383;
	exp_pow = (m->exp == 0) ? -16382 : exp_pow;
	if (m->exp != 32767 && zero)
	{
		ft_process_ld(m, exp_pow);
		ft_rounding(m, &format, exp_pow, 63);
		ft_get_ld(m, exp_pow);
		ft_fix_float(m, format);
	}
	else if (m->exp == 32767 && (f.t_comp.mantissa == 0) && f.t_comp.sign == 0)
		m->nbr = ft_strdup("inf");
	else if (m->exp == 32767 && (f.t_comp.mantissa == 0) && f.t_comp.sign == 1)
		m->nbr = ft_strdup("-inf");
	else if (m->exp == 32767 && (f.t_comp.mantissa != 0))
		m->nbr = ft_strdup("nan");
	else if (zero == 0)
		zero_f(m, format);
}
