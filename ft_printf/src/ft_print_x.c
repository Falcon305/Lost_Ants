/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:26 by yidabdes         ###   ########.fr       */
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

int			ft_print_hexa(unsigned long long int nbr, t_format f)
{
	char	*ret;
	char	*n;
	int		len;

	n = ft_setup_hex(nbr, f);
	len = ft_strlen(n);
	ret = ft_strdup(n);
	if (f.width > len)
	{
		free(ret);
		if (f.leftjustify || len == 0 || f.isprecised == 1)
			ret = ft_resize(f.width, 0);
		else if (f.leftjustify == 0)
			ret = ft_resize(f.width, f.padding);
		if (f.leftjustify)
			ft_cptostart(n, ret, ft_strlen(n));
		else
			ft_cptoend(n, ret, ft_strlen(n), ft_strlen(ret));
		if (f.padding == 1 && f.hash == 1 && f.leftjustify == 0)
			ft_fix_prefix(ret);
	}
	ft_str_toupper(ret, f.specifier);
	len = ft_printhex_getlen(ret);
	garbage(n, ret);
	return (len);
}

int			ft_printhex_getlen(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	while (i < len)
		ft_putchar(str[i++]);
	return (len);
}

char		*ft_setup_hex(unsigned long long int nbr, t_format format)
{
	char *num;

	num = NULL;
	num = ft_itoa_base(nbr, 16);
	if (format.isprecised == 1)
		num = ft_precise_hex(num, format.precision);
	if (format.hash == 1 && nbr != 0)
		num = ft_add_prefix(num, ft_strlen(num));
	return (num);
}

char		*ft_str_toupper(char *str, char specifer)
{
	int i;

	i = 0;
	if (specifer == 'x')
		return (str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
