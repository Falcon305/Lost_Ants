/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 00:08:43 by yidabdes          #+#    #+#             */
/*   Updated: 2020/01/10 19:59:06 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	garbage(char **str1, char **str2)
{
	if (*str1 != NULL)
		free(*str1);
	*str1 = ft_strdup(*str2);
	if (*str2 != NULL)
		free(*str2);
}

int			add_zeros(t_man *man, t_format format)
{
	int		i;
	int		p;
	int		len;
	char	*tmp;

	p = ft_strindex(man->nbr, '.');
	len = ft_strlen(man->nbr);
	i = 0;
	tmp = ft_strnew(format.precision + p + 1);
	tmp = ft_memset(tmp, '0', format.precision + p + 1);
	if (format.precision > (len - p))
	{
		while (i < len)
		{
			tmp[i] = man->nbr[i];
			i++;
		}
		free(man->nbr);
		man->nbr = tmp;
	}
	return (0);
}

void		ft_fix_float(t_man *man, t_format format)
{
	t_point	i;
	t_point	len;
	char	*tmp;
	int		p;

	i.n1 = 0;
	i.n2 = 0;
	p = ft_strindex(man->nbr, '.');
	len.n1 = ft_strlen(man->nbr);
	while (man->nbr[i.n1] == '0' && man->nbr[i.n1 + 1] != '.')
		i.n1++;
	len.n2 = len.n1 - i.n1 + 1;
	p -= i.n1;
	p = (format.precision == 0) ? p : p + 1;
	tmp = ft_strnew(len.n2);
	format.precision = (format.isprecised == 0) ? 6 : format.precision;
	while (i.n2 < len.n2)
	{
		if (i.n2 == (p + format.precision))
			break ;
		tmp[i.n2++] = man->nbr[i.n1++];
	}
	garbage(&man->nbr, &tmp);
	p = (i.n2 < (p + format.precision)) ? add_zeros(man, format) : 0;
}

int			round_it(char *nbr, int pos)
{
	int len;

	len = ft_strlen(nbr);
	pos++;
	while (pos < len)
	{
		if (nbr[pos] > '5')
			return (1);
		pos++;
	}
	return (0);
}

void		ft_rounding(t_man *m, t_format *f, int exp_pow, int l)
{
	t_point	i;
	t_point	mod;

	exp_pow = (exp_pow >= 0) ? 0 : exp_pow;
	i.n2 = ft_strlen(m->nbr);
	i.n1 = i.n2 + exp_pow - l;
	if ((f->precision == 0 && !f->isprecised) || f->precision < 0)
		f->precision = 6;
	mod.n1 = i.n1 + f->precision;
	mod.n2 = I(m->nbr[mod.n1 - 1]);
	if (mod.n1 > 0 && -i.n1 < l && i.n2 - i.n1 - f->precision > 0)
	{
		if (m->nbr[mod.n1] > '5')
			m->nbr = add(m->nbr, ft_power("10", (i.n2 - i.n1 - f->precision)));
		else if (m->nbr[mod.n1] == '5' && (mod.n2 % 2 != 0))
			m->nbr = add(m->nbr, ft_power("10", (i.n2 - i.n1 - f->precision)));
		else if (m->nbr[mod.n1] == '5' && (mod.n2 % 2 == 0) &&
			round_it(m->nbr, mod.n1))
			m->nbr = add(m->nbr, ft_power("10", (i.n2 - i.n1 - f->precision)));
	}
}
