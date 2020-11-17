/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:40:56 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:30 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_precise_hex(char *number, int precision)
{
	char	*ret;
	int		nlen;
	int		rlen;
	int		i;

	i = 0;
	nlen = ft_strlen(number);
	if (precision < nlen && ft_strcmp(number, "0") != 0)
		precision = ft_strlen(number);
	if (precision <= 0)
	{
		free(number);
		return (ft_resize(0, 0));
	}
	ret = ft_resize(precision, 1);
	rlen = ft_strlen(ret);
	rlen--;
	nlen--;
	while (i <= nlen)
	{
		ret[rlen - i] = number[nlen - i];
		i++;
	}
	free(number);
	return (ret);
}

char		*ft_resize_hex(char *number, int width, t_format format)
{
	char	*ret;
	int		nlen;
	int		rlen;
	int		i;

	i = 0;
	if (width <= 0)
		return (ft_resize(0, 0));
	ret = ft_resize(width, 0);
	nlen = ft_strlen(number);
	rlen = ft_strlen(ret);
	while (i < width)
		if (format.padding)
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	return (ret);
}

void		ft_cptoend(char *src, char *dest, int slen, int dlen)
{
	int i;

	i = 0;
	slen--;
	dlen--;
	while (i <= slen)
	{
		dest[dlen - i] = src[slen - i];
		i++;
	}
}

void		ft_cptostart(char *src, char *dest, int slen)
{
	int i;

	i = 0;
	slen--;
	while (i <= slen)
	{
		dest[i] = src[i];
		i++;
	}
}

void		ft_fix_prefix(char *str)
{
	int i;
	int isprefixed;
	int count;

	count = 0;
	isprefixed = 0;
	i = ft_strindex(str, 'x');
	if (i != -1)
	{
		isprefixed = 1;
		str[i] = '0';
	}
	i = 0;
	while (str[i] && isprefixed)
	{
		if (str[i] == '0')
			count++;
		if (count == 2)
		{
			str[i] = 'x';
			break ;
		}
		i++;
	}
}
