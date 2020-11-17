/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct_pars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:28:09 by yidabdes          #+#    #+#             */
/*   Updated: 2020/01/30 17:06:00 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		ft_free_rooms(t_room *rooms, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (rooms[i].name != NULL)
			free(rooms[i].name);
		i++;
	}
	if (rooms != NULL)
		free(rooms);
	rooms = NULL;
}

void		ft_free_adj(t_graph *g)
{
	int i;

	i = 0;
	while (i < g->nbr_verts)
	{
		if (g->adj[i] != NULL)
			free(g->adj[i]);
		i++;
	}
	if (g->adj != NULL)
		free(g->adj);
	g->adj = NULL;
}

void		ft_free_struct_pars(t_graph *g, t_data *head)
{
	ft_free_list(head);
	ft_free_rooms(g->verts, g->nbr_verts);
	ft_free_adj(g);
}
