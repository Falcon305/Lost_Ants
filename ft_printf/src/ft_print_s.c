/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:18 by yidabdes         ###   ########.fr       */
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

int			ft_print_string(va_list args, t_format f)
{
	char	*initialstr;
	char	*r;
	t_point	i;

	initialstr = ft_strdup(va_arg(args, char*));
	(initialstr == NULL) ? (initialstr = ft_strdup("(null)")) : 0;
	r = ft_strdup(initialstr);
	i.n1 = ft_strlen(initialstr);
	i.n2 = 0;
	if (f.precision >= 0 && f.isprecised == 1)
	{
		initialstr = ft_precise(initialstr, f.precision);
		i.n1 = ft_strlen(initialstr);
	}
	if (f.width > i.n1)
	{
		free(r);
		r = ft_resize(f.width, f.padding && !f.isprecised && !f.leftjustify);
		r = ft_reform(initialstr, r, f.leftjustify);
		i.n1 = ft_strlen(r);
	}
	while (i.n2 < i.n1)
		ft_putchar(r[i.n2++]);
	garbage(r, initialstr);
	return (i.n1);
}

char		*ft_precise(char *str, int precision)
{
	int		i;
	char	*ret;

	if (precision == 0)
	{
		free(str);
		return (ft_strnew(0));
	}
	i = -1;
	if (!(ret = (char*)malloc(sizeof(char) * precision + 1)))
		return (NULL);
	else
		ret[precision] = '\0';
	while (++i < precision)
		ret[i] = str[i];
	free(str);
	return (ret);
}

char		*ft_putatstart(char *src, char *dest, int lsrc, int ldest)
{
	int i;

	i = 0;
	while (i < lsrc && i < ldest)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char		*ft_putatend(char *src, char *dest, int lsrc, int ldest)
{
	int i;

	i = 0;
	lsrc--;
	ldest--;
	while (lsrc - i >= 0)
	{
		dest[ldest - i] = src[lsrc - i];
		i++;
	}
	return (dest);
}
