/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:44:17 by yidabdes          #+#    #+#             */
/*   Updated: 2019/07/30 16:07:14 by yidabdes         ###   ########.fr       */
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

int			ft_print_pointer(va_list args, t_format format)
{
	char				*ret;
	unsigned long int	adress;
	char				*hexofaddress;
	int					len;
	int					i;

	i = 0;
	len = 0;
	adress = va_arg(args, unsigned long int);
	hexofaddress = ft_itoa_base(adress, 16);
	len = ft_strlen(hexofaddress);
	hexofaddress = ft_add_prefix(hexofaddress, len);
	len = ft_strlen(hexofaddress);
	ret = ft_strdup(hexofaddress);
	if (format.width > len)
	{
		free(ret);
		ret = ft_resize(format.width, 0);
		ret = ft_reform(hexofaddress, ret, format.leftjustify);
		len = ft_strlen(ret);
	}
	while (i < len)
		ft_putchar(ret[i++]);
	garbage(ret, hexofaddress);
	return (len);
}

char		*ft_add_prefix(char *str, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_resize(len + 2, 0);
	ret[0] = '0';
	ret[1] = 'x';
	while (i < len)
	{
		ret[i + 2] = str[i];
		i++;
	}
	free(str);
	return (ret);
}
