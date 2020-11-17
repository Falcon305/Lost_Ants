/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:23 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_print_unsigned(unsigned long long int nbr, t_format f)
{
	char	*ret;
	char	*number;
	int		len;
	int		i;

	i = 0;
	len = 0;
	number = ft_setup_unsigned(nbr, f);
	len = ft_strlen(number);
	ret = ft_strdup(number);
	if (f.width > len)
	{
		f.padding = (f.isprecised || f.leftjustify) ? 0 : f.padding;
		free(ret);
		ret = ft_reform(number, ft_resize(f.width, f.padding), f.leftjustify);
		len = ft_strlen(ret);
	}
	while (i < len)
		ft_putchar(ret[i++]);
	if (ret != NULL)
		free(ret);
	if (number != NULL)
		free(number);
	return (len);
}

char	*ft_setup_unsigned(unsigned long long int nbr, t_format format)
{
	char *number;

	number = NULL;
	number = ft_itoa_base(nbr, 10);
	if (format.precision == 0 && format.isprecised == 1 && nbr != 0)
		format.precision++;
	if (format.isprecised == 1)
		number = ft_precise_hex(number, format.precision);
	return (number);
}
