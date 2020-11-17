/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:36 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_initialise(t_format *format)
{
	format->padding = 0;
	format->leftjustify = 0;
	format->hash = 0;
	format->sign = 0;
	format->space = 0;
	format->width = 0;
	format->isprecised = 0;
	format->precision = 0;
	format->modifer = 'n';
	format->specifier = 'n';
}

int			is_specifier(char c)
{
	char	specifiers[11];
	int		i;

	i = 0;
	specifiers[0] = 'c';
	specifiers[1] = 's';
	specifiers[2] = 'p';
	specifiers[3] = 'd';
	specifiers[4] = 'i';
	specifiers[5] = 'o';
	specifiers[6] = 'u';
	specifiers[7] = 'x';
	specifiers[8] = 'X';
	specifiers[9] = 'f';
	specifiers[10] = '\0';
	while (specifiers[i])
	{
		if (specifiers[i++] == c)
			return (1);
	}
	return (0);
}

int			ft_print_params(va_list args, t_format format)
{
	int count;

	count = 0;
	if (format.specifier == 'c')
		count = ft_print_char(args, format);
	else if (format.specifier == 's')
		count = ft_print_string(args, format);
	else if (format.specifier == 'p')
		count = ft_print_pointer(args, format);
	else if (ft_strchr("di", format.specifier))
		count = ft_convert_id(args, format);
	else if (ft_strchr("ouxX", format.specifier))
		count = ft_convert_oux(args, format);
	else if (format.specifier == 'f')
		count = ft_convert_double(args, format);
	return (count);
}

int			ft_convert_double(va_list args, t_format format)
{
	long double nbr;

	nbr = 0;
	if (format.modifer == 'L')
	{
		nbr = va_arg(args, long double);
		return (ft_print_lf(nbr, format));
	}
	else
	{
		nbr = va_arg(args, double);
		return (ft_print_f(nbr, format));
	}
	return (0);
}

int			ft_convert_id(va_list args, t_format format)
{
	long long int nbr;

	nbr = 0;
	if (format.modifer == 'L')
		nbr = va_arg(args, long long int);
	else if (format.modifer == 'l')
		nbr = va_arg(args, long int);
	else if (format.modifer == 'H')
		nbr = (char)va_arg(args, int);
	else if (format.modifer == 'h')
		nbr = (short)va_arg(args, int);
	else
		nbr = va_arg(args, int);
	if (format.specifier == 'i' || format.specifier == 'd')
		return (ft_print_int(nbr, format));
	return (0);
}
