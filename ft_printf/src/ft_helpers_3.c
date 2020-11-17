/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 02:35:07 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:43 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_convert_oux(va_list args, t_format format)
{
	unsigned long long int nbr;

	nbr = 0;
	if (format.modifer == 'L')
		nbr = va_arg(args, unsigned long long int);
	else if (format.modifer == 'l')
		nbr = va_arg(args, unsigned long int);
	else if (format.modifer == 'H')
		nbr = (unsigned char)va_arg(args, unsigned int);
	else if (format.modifer == 'h')
		nbr = (unsigned short int)va_arg(args, int);
	else
		nbr = va_arg(args, unsigned int);
	if (format.specifier == 'x' || format.specifier == 'X')
		return (ft_print_hexa(nbr, format));
	else if (format.specifier == 'o')
		return (ft_print_octal(nbr, format));
	else if (format.specifier == 'u')
		return (ft_print_unsigned(nbr, format));
	return (0);
}

void		ft_print_re(char *ret, int *len)
{
	ft_fix_sign(ret);
	ft_putstr(ret);
	*len = ft_strlen(ret);
}

int			is_modifier(char c)
{
	if (c == 'l' || c == 'h')
		return (1);
	return (0);
}

void		ft_get_modifier(char *str, t_format *format)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_specifier(str[i]) == 0)
	{
		if (str[i] == str[i + 1] && is_modifier(str[i]))
		{
			format->modifer = str[i] - 'a' + 'A';
			break ;
		}
		else if (is_modifier(str[i]) && !is_modifier(str[i + 1]))
		{
			format->modifer = str[i];
			break ;
		}
		else if (str[i] == 'L')
		{
			format->modifer = 'L';
			break ;
		}
		i++;
	}
}
