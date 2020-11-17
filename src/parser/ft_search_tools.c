/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:36:06 by yidabdes          #+#    #+#             */
/*   Updated: 2020/01/30 17:10:01 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	ft_is_start_end(t_graph *g, int i, int j)
{
	if (g->verts[i].type == 1)
		g->start = i;
	if (g->verts[i].type == 2)
		g->end = i;
	if (g->verts[j].type == 1)
		g->start = j;
	if (g->verts[j].type == 2)
		g->end = j;
}

void	ft_sort_rooms(t_graph *g)
{
	t_room	tmp;
	int		i;
	int		j;
	int		sorted;

	i = -1;
	sorted = 1;
	while (++i < (g->nbr_verts - 1))
	{
		j = i + 1;
		while (j < g->nbr_verts)
		{
			if (ft_strcmp(g->verts[i].name, g->verts[j].name) > 0)
			{
				sorted = 0;
				tmp = g->verts[i];
				g->verts[i] = g->verts[j];
				g->verts[j] = tmp;
				ft_is_start_end(g, i, j);
			}
			if (sorted == 1)
				ft_is_start_end(g, i, j);
			j++;
		}
	}
}

int		ft_binary_search(t_graph *g, int start, int end, char *room)
{
	int		middle;

	middle = start + (end - start) / 2;
	if (middle > (g->nbr_verts - 1))
		return (-1);
	if (end >= start)
	{
		if (ft_strcmp(g->verts[middle].name, room) == 0)
			return (middle);
		if (ft_strcmp(g->verts[middle].name, room) > 0)
			return (ft_binary_search(g, start, middle - 1, room));
		return (ft_binary_search(g, middle + 1, end, room));
	}
	return (-1);
}
