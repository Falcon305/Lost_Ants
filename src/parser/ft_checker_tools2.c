/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_tools2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:51:32 by yidabdes          #+#    #+#             */
/*   Updated: 2020/02/10 21:18:14 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		ft_checker_room_template(char *line)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i] != NULL)
	{
		j = 0;
		if ((i > 0) && (j == 0) && (tab[i][j] == '-' || tab[i][j] == '+'))
			j++;
		if (i == 0 && j == 0 && (tab[i][j] == 'L'))
			return (0);
		while (i > 0 && tab[i][j] != '\0')
		{
			if (ft_isdigit(tab[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	ft_garbadge(tab);
	if (i != 3)
		return (0);
	return (1);
}

int		ft_check_room(t_data **head, char *line, t_graph **g)
{
	int c;

	c = 0;
	c = ft_strindex(line, '-');
	if (c == -1 && ft_checker_room_template(line))
	{
		ft_add_list(head, ROOM, line);
		(*g)->nbr_verts++;
	}
	else if (LINK == ft_check_link(head, line))
		return (END_OF_ROOMS);
	else
		return (ROOM_ERROR);
	if (ft_count_char(line, ' ') != 2 || c != -1)
		return (ROOM_ERROR);
	return (ROOM);
}

int		ft_checker(t_data **head, char *line, int i, t_graph *g)
{
	int ret;

	ret = NO_MATCH;
	if (i == 0 && (ret = ft_check_ants(head, line)) == ANTS)
		return (ANTS);
	else if (i == 0 && (ret = ft_check_ants(head, line)) != ANTS)
		return (ANTS_ERROR);
	else if (i > 0)
	{
		ret = ft_check_command_comment(head, line);
		if (ret == NO_MATCH && (g->valid))
			ret = ft_check_room(head, line, &g);
		if (ret == END_OF_ROOMS)
			(*g).valid = 0;
		if (ret == NO_MATCH)
			ret = ft_check_link(head, line);
	}
	return (ret);
}

int		ft_checker_next_one(t_data *current)
{
	if (current->next != NULL)
	{
		if (current->id == 4 && current->next->id != 6)
			return (NO_START);
		if (current->id == 5 && current->next->id != 6)
			return (NO_END);
	}
	return (1);
}

int		ft_check_start_end(t_data **head, int *nbr_links)
{
	t_data	*current;
	int		start;
	int		end;

	start = 0;
	end = 0;
	current = *head;
	while (current)
	{
		if (ft_checker_next_one(current) != 1)
			return (ft_checker_next_one(current));
		if (current->id == 4)
			start++;
		if (current->id == 5)
			end++;
		if (current->id == 7)
			(*nbr_links)++;
		current = current->next;
	}
	if (start != 1 || end != 1)
		return (ORDER_ERROR);
	return (1);
}
