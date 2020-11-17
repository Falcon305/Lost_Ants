/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:33 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_isallowed(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '.' || c == '+' || c == '-'
		|| c == '#')
		return (1);
	return (0);
}

int			ft_percent_check(char *str, int *printed)
{
	int		i;
	char	*cut;

	cut = NULL;
	i = 1;
	while (str[i] != '%' && ft_isallowed(str[i]))
		i++;
	if (str[i] != '%')
	{
		ft_printf("");
		if (str[i] == 'h' || str[i] == 'l' ||
			(str[i] == 'h' && str[i + 1] == 'h') || (str[i] == 'l' &&
				str[i] == 'l') || str[i] == 'L')
			i++;
		return (i);
	}
	else
	{
		cut = ft_strsub(str, 0, i + 1);
		cut[i] = 'c';
		(*printed) += ft_printf(cut, '%');
	}
	free(cut);
	return (i + 1);
}

void		ft_putchar_rn(char c, int *ret)
{
	(*ret)++;
	ft_putchar(c);
}

int			have_specifier(int i, char *str)
{
	int j;

	j = i + 1;
	while (is_specifier(str[j]) == 0 && str[j] != '\0')
	{
		if (str[j] == '%')
			return (0);
		j++;
	}
	if (str[j] != '\0')
		return (j);
	return (0);
}

int			ft_format(char *str, va_list args)
{
	int			i;
	int			j;
	char		*cut;
	t_format	format;
	int			printed;

	printed = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && (j = have_specifier(i, str)))
		{
			cut = ft_strsub(str, i, j);
			i += (j - i + 1);
			format = ft_get_format(cut);
			format.specifier = str[j];
			printed += ft_print_params(args, format);
			free(cut);
		}
		else if (str[i] == '%' && have_specifier(i, str) == 0)
			i += ft_percent_check(str + i, &printed);
		else
			ft_putchar_rn(str[i++], &printed);
	}
	return (printed);
}
