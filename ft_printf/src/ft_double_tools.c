/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 22:40:15 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:23 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fix_mantissa(char *man)
{
	char	*res;
	int		i;
	int		j;

	i = 52 - ft_strlen(man);
	j = 0;
	res = ft_strnew(52);
	res = ft_memset(res, '0', 52);
	while (i < 52)
		res[i++] = man[j++];
	if (man != NULL)
		free(man);
	return (res);
}

static void		ft_get_d(t_man *m, int exp_pow)
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
	m->pos = len + exp_pow - 52;
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

static void		ft_process_d(t_man *m, int exp_pow)
{
	int		i;
	char	*tmp;

	i = 0;
	m->pos = 1;
	m->man = ((ft_strlen(m->man) < 52)) ? ft_fix_mantissa(m->man) : m->man;
	m->nbr = (m->exp == 0) ? ft_strdup("0") : ft_strdup("1");
	while (i < 52)
	{
		tmp = ft_strdup(m->nbr);
		free(m->nbr);
		m->nbr = multiply(tmp, ft_strdup("10"));
		if (m->man[i] == '1')
			m->nbr = add(m->nbr, ft_power("5", (i + 1)));
		i++;
	}
	if (exp_pow < 0)
		m->nbr = multiply(m->nbr, ft_power("5", -exp_pow));
	else
		m->nbr = multiply(m->nbr, ft_power("2", exp_pow));
	m->nbr = ft_rm_zeros(m->nbr);
}

void			zero_f(t_man *m, t_format f)
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

void			ft_double_print(t_float f, t_man *m, t_format format)
{
	int	exp_pow;
	int	zero;

	zero = (f.t_comp.exponent == 0 && f.t_comp.mantissa == 0) ? 0 : 1;
	m->man = ft_itoa_base(f.t_comp.mantissa, 2);
	m->exp = f.t_comp.exponent;
	exp_pow = m->exp - 1023;
	exp_pow = (m->exp == 0) ? -1022 : exp_pow;
	if (m->exp != 2047 && zero)
	{
		ft_process_d(m, exp_pow);
		ft_rounding(m, &format, exp_pow, 52);
		ft_get_d(m, exp_pow);
		ft_fix_float(m, format);
	}
	else if (m->exp == 2047 && (f.t_comp.mantissa == 0) && f.t_comp.sign == 0)
		m->nbr = ft_strdup("inf");
	else if (m->exp == 2047 && (f.t_comp.mantissa == 0) && f.t_comp.sign == 1)
		m->nbr = ft_strdup("-inf");
	else if (m->exp == 2047 && (f.t_comp.mantissa != 0))
		m->nbr = ft_strdup("nan");
	else if (zero == 0)
		zero_f(m, format);
}
