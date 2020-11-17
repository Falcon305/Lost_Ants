/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 02:35:07 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:39 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_format	ft_get_format(char *str)
{
	t_format	format;
	int			i;

	i = 0;
	ft_initialise(&format);
	ft_get_padding(str, &format);
	ft_get_flags(str, &format);
	ft_get_width(str, &format);
	ft_get_precision(str, &format);
	ft_get_modifier(str, &format);
	if (format.width < 0)
		format.width = 0;
	return (format);
}

void		ft_get_flags(char *str, t_format *format)
{
	int i;

	i = 0;
	while (str[i] && is_specifier(str[i]) == 0)
	{
		if (str[i] == '#')
			format->hash = 1;
		else if (str[i] == '+')
			format->sign = 1;
		else if (str[i] == '-')
			format->leftjustify = 1;
		else if (str[i] == ' ')
			format->space = 1;
		i++;
	}
}

void		ft_get_width(char *str, t_format *format)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_specifier(str[i]) == 0 && str[i] != '.')
	{
		if (str[i] == '0')
		{
			i++;
			continue ;
		}
		else if (ft_isdigit(str[i]))
		{
			format->width = ft_atoi(&str[i]);
			if (format->width < 0)
				format->width = 0;
			break ;
		}
		i++;
	}
}

void		ft_get_precision(char *str, t_format *format)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_specifier(str[i]) == 0)
	{
		if (str[i] == '.')
			format->isprecised = 1;
		if (str[i] == '.' && ft_isdigit(str[i + 1]))
		{
			format->precision = ft_atoi(&str[i + 1]);
			break ;
		}
		i++;
	}
}

void		ft_get_padding(char *str, t_format *format)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_specifier(str[i]) == 0)
	{
		if ((str[i] == '0' && str[i - 1] == '%') || (str[i] == '0'
			&& str[i - 1] == ' ') || (str[i] == '0' && str[i - 1] == '#')
			|| (str[i] == '0' && str[i - 1] == '+') ||
			(str[i] == '0' && i == 0))
		{
			format->padding = 1;
			break ;
		}
		i++;
	}
}
