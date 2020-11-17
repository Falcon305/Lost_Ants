/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_tools1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:47:54 by yidabdes          #+#    #+#             */
/*   Updated: 2020/01/30 16:53:15 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		ft_check_ants(t_data **head, char *line)
{
	int i;

	i = 0;
	if (ft_atoi(line) <= 0 || ft_atoi(line) > 2147483647)
		return (ANTS_ERROR);
	if (line[0] == '+')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (i == (int)ft_strlen(line))
	{
		ft_add_list(head, ANTS, line);
		return (ANTS);
	}
	return (ANTS_ERROR);
}

int		ft_check_command_comment(t_data **head, char *line)
{
	int ret;

	ret = NO_MATCH;
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			if (ft_strcmp(line + 2, "start") == 0)
				ret = START;
			else if (ft_strcmp(line + 2, "end") == 0)
				ret = END;
			else
				ret = COMMAND;
		}
		else if (line[1] != '#')
			ret = COMMENT;
	}
	if (ret != NO_MATCH)
		ft_add_list(head, ret, line);
	return (ret);
}

int		ft_look_up(char *line, int c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, c);
	while (tab[i] != NULL)
		i++;
	ft_garbadge(tab);
	return (i);
}

int		ft_check_link(t_data **head, char *line)
{
	int		i;
	int		j;

	j = 0;
	i = ft_look_up(line, ' ');
	if (i == 1)
	{
		if ((j = ft_strindex(line, '-')) != -1)
		{
			if (line[j + 1] != '-' && line[j + 1] != '\0')
				ft_add_list(head, LINK, line);
			else
				return (LINK_ERROR);
		}
		else
			return (LINK_ERROR);
	}
	else
		return (LINK_ERROR);
	i = ft_count_char(line, '-');
	if (i != 1)
		return (LINK_ERROR);
	return (LINK);
}

int		ft_count_char(char *line, char c)
{
	int ret;
	int	i;

	i = 0;
	ret = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			ret++;
		i++;
	}
	return (ret);
}
