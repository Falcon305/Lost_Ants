/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:58:57 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:59 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		garbage(char *str1, char *str2, char *str3)
{
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
	if (str3 != NULL)
		free(str3);
}

char			*ft_hash(char *number, t_format f)
{
	char	*tmp;
	int		len;

	if (ft_strcmp(number, "inf") == 0 || ft_strcmp(number, "-inf") == 0 ||
		ft_strcmp(number, "nan") == 0)
		return (number);
	if (f.isprecised == 1 && f.precision == 0 && f.hash == 1)
	{
		len = ft_strlen(number);
		tmp = ft_resize(len + 1, 0);
		ft_strcpy(tmp, number);
		free(number);
		tmp[len] = '.';
		return (tmp);
	}
	return (number);
}

char			*ft_float_sign(char *number, int sign, t_format format)
{
	char	*ret;
	int		s_len;

	number = ft_hash(number, format);
	s_len = ft_strlen(number);
	if (sign == 1 || (sign == 0 && format.sign == 1) || (sign == 0 &&
		format.space == 1))
	{
		ret = ft_resize(s_len + 1, format.padding);
		if (sign == 1)
			ret[0] = '-';
		else if (sign == 0 && format.sign == 1)
			ret[0] = '+';
		else if (sign == 0 && format.space == 1)
			ret[0] = ' ';
		ft_cptoend(number, ret, s_len, ft_strlen(ret));
		if (number != NULL)
			free(number);
		return (ret);
	}
	return (number);
}

int				ft_print_f(double nbr, t_format fr)
{
	int			len;
	char		*ret;
	t_man		m;
	t_float		f;

	f.f = nbr;
	ft_double_print(f, &m, fr);
	if (ft_strcmp(m.nbr, "-inf") != 0 && ft_strcmp(m.nbr, "nan") != 0)
		m.nbr = ft_float_sign(m.nbr, f.t_comp.sign, fr);
	len = ft_strlen(m.nbr);
	ret = ft_strdup(m.nbr);
	if (fr.width > len)
	{
		fr.padding = (fr.leftjustify == 1 && fr.padding == 1) ? 0 : fr.padding;
		if (ft_strcmp(m.nbr, "inf") == 0 || ft_strcmp(m.nbr, "+inf") == 0 ||
			ft_strcmp(m.nbr, "-inf") == 0 || ft_strcmp(m.nbr, "nan") == 0)
			fr.padding = 0;
		free(ret);
		ret = ft_resize(fr.width, fr.padding);
		(fr.leftjustify == 1) ? ft_cptostart(m.nbr, ret, len) :
		ft_cptoend(m.nbr, ret, len, ft_strlen(ret));
	}
	ft_print_re(ret, &len);
	garbage(m.nbr, m.man, ret);
	return (len);
}

int				ft_print_lf(long double nbr, t_format fr)
{
	int				len;
	char			*ret;
	t_man			m;
	t_long_float	f;

	f.f = nbr;
	ft_ldouble_print(f, &m, fr);
	if (ft_strcmp(m.nbr, "-inf") != 0 && ft_strcmp(m.nbr, "nan") != 0)
		m.nbr = ft_float_sign(m.nbr, f.t_comp.sign, fr);
	len = ft_strlen(m.nbr);
	ret = m.nbr;
	if (fr.width > len)
	{
		fr.padding = (fr.leftjustify == 1 && fr.padding == 1) ? 0 : fr.padding;
		if (ft_strcmp(m.nbr, "inf") == 0 || ft_strcmp(m.nbr, "+inf") == 0 ||
			ft_strcmp(m.nbr, "-inf") == 0 || ft_strcmp(m.nbr, "nan") == 0)
			fr.padding = 0;
		free(ret);
		ret = ft_resize(fr.width, fr.padding);
		(fr.leftjustify == 1) ? ft_cptostart(m.nbr, ret, len) :
		ft_cptoend(m.nbr, ret, len, ft_strlen(ret));
	}
	ft_print_re(ret, &len);
	garbage(m.man, ret, NULL);
	return (len);
}
