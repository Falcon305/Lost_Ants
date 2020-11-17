/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:56 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		garbage(char *str)
{
	if (str != NULL)
		free(str);
}

int				ft_print_char(va_list args, t_format f)
{
	char	*r;
	char	c;
	int		i;
	int		len;

	c = va_arg(args, int);
	i = -1;
	len = 0;
	r = NULL;
	if (f.width > 0)
	{
		r = ft_resize(f.width, f.padding && !f.isprecised && !f.leftjustify);
		len = ft_strlen(r);
		if (f.leftjustify == 1)
			r[0] = c;
		else
			r[len - 1] = c;
	}
	if ((r == NULL) && (len += 1))
		ft_putchar(c);
	else
		while (i++ < len - 1)
			ft_putchar(r[i]);
	garbage(r);
	return (len);
}

char			*ft_resize(int width, char zeropad)
{
	char	*ret;

	if (zeropad == 0)
		zeropad = ' ';
	else
		zeropad = '0';
	ret = ft_strnew(width);
	ft_memset(ret, zeropad, width);
	return (ret);
}

char			*ft_reform(char *src, char *dest, int position)
{
	int		lsrc;
	int		ldest;
	char	*ret;

	lsrc = ft_strlen(src);
	ldest = ft_strlen(dest);
	if (lsrc >= ldest)
		return (ft_strdup(src));
	else
	{
		if (position == 1)
			ret = ft_strdup(ft_putatstart(src, dest, lsrc, ldest));
		else
			ret = ft_strdup(ft_putatend(src, dest, lsrc, ldest));
	}
	free(dest);
	return (ret);
}
