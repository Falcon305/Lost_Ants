/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:58:18 by yidabdes          #+#    #+#             */
/*   Updated: 2020/02/09 09:14:57 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		**ft_alloc_adj(int size)
{
	int		i;
	int		j;
	int		**adj;

	i = 0;
	adj = (int **)malloc(sizeof(int *) * size);
	if (adj == NULL)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		j = 0;
		adj[i] = (int *)malloc(sizeof(int) * size);
		if (adj[i] == NULL)
			exit(EXIT_FAILURE);
		while (j < size)
			adj[i][j++] = 0;
		i++;
	}
	return (adj);
}

void	ft_fill_rooms(t_graph **g, char **tab, int *i)
{
	(*g)->verts[*i].name = ft_strdup(tab[0]);
	(*g)->verts[*i].cords.x = ft_atoi(tab[1]);
	(*g)->verts[*i].cords.y = ft_atoi(tab[2]);
	(*g)->verts[*i].list = NULL;
	(*g)->verts[*i].blocked = 0;
	(*g)->verts[*i].full = 0;
}

void	ft_fill_rooms_data(t_graph **g, int *i, t_data **cur)
{
	char	**tab;

	if (((*cur)->id == 4 || (*cur)->id == 5) && (*cur)->next->id == 6)
	{
		(*g)->verts[*i].type = (*cur)->id - 3;
		(*cur) = (*cur)->next;
	}
	else
		(*g)->verts[*i].type = 0;
	if ((*cur)->id == 6)
	{
		tab = ft_strsplit((*cur)->data, ' ');
		ft_fill_rooms(g, tab, i);
		ft_garbadge(tab);
		(*i)++;
		if (*i == (*g)->nbr_verts)
		{
			ft_sort_rooms(*g);
			if (((*g)->adj = ft_alloc_adj((*g)->nbr_verts)) == NULL)
				exit(EXIT_FAILURE);
		}
	}
}

int		ft_fill_links_data(t_graph *g, t_data *current)
{
	int		i;
	int		j;
	char	**tab;

	i = -1;
	j = -1;
	if (current->id == 7)
	{
		tab = ft_strsplit(current->data, '-');
		i = ft_binary_search(g, 0, g->nbr_verts, tab[0]);
		j = ft_binary_search(g, 0, g->nbr_verts, tab[1]);
		ft_garbadge(tab);
		if (i == -1 || j == -1)
			return (-1);
		g->adj[i][j] = 1;
		g->adj[j][i] = 1;
	}
	return (1);
}

int		ft_fill_it(t_data **head, t_graph *g)
{
	int		i;
	t_data	*current;

	i = 0;
	current = *head;
	while (current)
	{
		if (i < g->nbr_verts)
			ft_fill_rooms_data(&g, &i, &current);
		else
		{
			if (ft_fill_links_data(g, current) == -1)
			{
				ft_free_struct_pars(g, *head);
				return (-1);
			}
		}
		current = current->next;
	}
	return (1);
}
