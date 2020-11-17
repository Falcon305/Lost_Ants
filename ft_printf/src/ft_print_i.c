/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:03 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	garbage(char *str1, char *str2)
{
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
}

static void	ft_fix_width(t_format *f, char **ret, char *number, int *len)
{
	if (f->width > *len)
	{
		f->padding = (f->isprecised || f->leftjustify) ? 0 : f->padding;
		free(*ret);
		*ret = ft_resize(f->width, f->padding);
		*ret = ft_reform(number, *ret, f->leftjustify);
		*len = ft_strlen(*ret);
	}
}

int			ft_print_int(long long int nbr, t_format f)
{
	char	*ret;
	char	*number;
	int		len;
	int		i;

	i = 0;
	number = ft_itoa(nbr);
	if (f.isprecised)
		number = ft_precise_int(number, nbr, f);
	if (nbr >= 0 && (f.sign == 1 || f.space == 1))
		number = ft_sign(number, f);
	len = ft_strlen(number);
	ret = ft_strdup(number);
	ft_fix_width(&f, &ret, number, &len);
	if (nbr < 0 || f.sign == 1)
		ret = ft_fix_sign(ret);
	else if (f.space == 1)
		ret = ft_fix_space(ret);
	ft_putstr(ret);
	garbage(ret, number);
	return (len);
}

char		*ft_precise_int(char *number, long long int nbr, t_format format)
{
	char	*ret;
	int		s_len;
	int		d_len;
	int		i;

	i = 0;
	s_len = ft_strlen(number);
	if (format.precision < s_len && ft_strcmp(number, "0") != 0)
		return (number);
	if (format.precision == 0 && format.isprecised == 1)
	{
		free(number);
		return (ft_strnew(1));
	}
	if (nbr < 0)
		ret = ft_resize(format.precision + 1, 1);
	else
		ret = ft_resize(format.precision, 1);
	d_len = ft_strlen(ret);
	ft_cptoend(number, ret, s_len, d_len);
	garbage(number, NULL);
	return (ret);
}

char		*ft_sign(char *number, t_format f)
{
	char	*ret;
	int		s_len;
	int		d_len;
	int		i;

	i = 0;
	ret = NULL;
	if (f.sign == 0 && f.space == 0)
		return (number);
	s_len = ft_strlen(number);
	garbage(ret, NULL);
	ret = ft_resize(ft_strlen(number) + 1, 1);
	d_len = ft_strlen(ret);
	ft_cptoend(number, ret, s_len, d_len);
	if (f.sign == 1)
		ret[i] = '+';
	else if (f.space == 1)
		ret[i] = ' ';
	garbage(number, NULL);
	return (ret);
}
