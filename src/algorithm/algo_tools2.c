/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:29:28 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/14 20:53:01 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void					visited(t_graph *g)
{
	int i;

	i = 0;
	while (i < g->nbr_verts)
	{
		g->verts[i].visited = 0;
		i++;
	}
}

int						end_road(t_graph *g, int room)
{
	int i;

	i = 0;
	while (i < g->nbr_verts)
	{
		if (g->adj[room][i] == 1 && g->verts[i].blocked == 1 &&
				g->cap[room][i] > 0)
			return (0);
		i++;
	}
	return (1);
}

t_elt					*insert_top(int num, t_elt *head)
{
	t_elt *new_node;

	new_node = (t_elt *)malloc(sizeof(t_elt));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = num;
	new_node->next = head;
	head = new_node;
	return (head);
}

void					n_list(t_graph *g, int node)
{
	int i;

	i = 0;
	while (i < g->nbr_verts)
	{
		if (g->adj[node][i] == 1)
			g->verts[node].list = insert_top(i, g->verts[node].list);
		i++;
	}
}

void					build_list(t_graph *g)
{
	int node;

	node = 0;
	while (node < g->nbr_verts)
	{
		n_list(g, node);
		node++;
	}
}
