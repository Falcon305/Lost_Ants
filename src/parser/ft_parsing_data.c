/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:59:44 by yidabdes          #+#    #+#             */
/*   Updated: 2020/02/09 14:33:32 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int			ft_start_end_linked(t_graph *g)
{
	int	start;
	int	end;
	int i;

	start = 0;
	end = 0;
	i = 0;
	while (i < g->nbr_verts)
	{
		if (g->adj[g->start][i] == 1)
			start = 1;
		if (g->adj[g->end][i] == 1)
			end = 1;
		i++;
	}
	if (start == 0 || end == 0)
		return (-1);
	return (1);
}

int			ft_get_rooms_links(t_data **head, t_graph *g)
{
	(*g).verts = (t_room *)malloc(sizeof(t_room) * (*g).nbr_verts);
	if ((*g).verts == NULL)
		exit(EXIT_FAILURE);
	if (ft_fill_it(head, g) == -1)
		return (-1);
	return (1);
}

void		ft_init_g(t_graph *g)
{
	g->valid = 1;
	g->nbr_verts = 0;
}

int			ft_parsing_data(t_graph *g, t_data **head)
{
	int		ret;
	int		nbr_links;

	nbr_links = 0;
	ft_init_g(g);
	ret = ft_read_data(head, &nbr_links, g);
	if (nbr_links == 0 || ret != 1)
	{
		ft_free_list(*head);
		return (-1);
	}
	g->ants = ft_atoi((*head)->data);
	if (ft_get_rooms_links(head, g) == -1)
		return (-1);
	if (ft_start_end_linked(g) != 1)
	{
		ft_free_struct_pars(g, *head);
		return (-1);
	}
	if (ft_strcmp(g->verts[g->start].name, g->verts[g->end].name) == 0)
	{
		ft_free_struct_pars(g, *head);
		return (-1);
	}
	return (1);
}
