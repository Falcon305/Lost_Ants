/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:56:13 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:09 by yidabdes         ###   ########.fr       */
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

int			ft_print_octal(unsigned long long int nbr, t_format f)
{
	char	*ret;
	char	*number;
	int		len;
	int		i;

	i = 0;
	len = 0;
	number = ft_setup_octal(nbr, f);
	len = ft_strlen(number);
	ret = ft_strdup(number);
	if (f.width > len)
	{
		f.padding = (f.isprecised || f.leftjustify) ? 0 : f.padding;
		free(ret);
		ret = ft_resize(f.width, f.padding);
		ret = ft_reform(number, ret, f.leftjustify);
		len = ft_strlen(ret);
	}
	while (i < len)
		ft_putchar(ret[i++]);
	garbage(number, ret);
	return (len);
}

char		*ft_setup_octal(unsigned long long int nbr, t_format format)
{
	char *number;

	number = NULL;
	number = ft_itoa_base(nbr, 8);
	if (format.precision == 0 && format.isprecised == 1 && nbr != 0)
		format.precision++;
	if (format.isprecised == 1)
		number = ft_precise_hex(number, format.precision);
	if (format.hash == 1 && nbr != 0)
		number = ft_add_prefix_o(number);
	if (format.hash == 1 && ft_strlen(number) == 0)
		number = ft_add_prefix_o(number);
	return (number);
}

char		*ft_add_prefix_o(char *str)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	if (str[0] == '0')
		return (str);
	len = ft_strlen(str);
	ret = ft_resize(len + 1, 0);
	ret[0] = '0';
	while (i < len)
	{
		ret[i + 1] = str[i];
		i++;
	}
	free(str);
	return (ret);
}
