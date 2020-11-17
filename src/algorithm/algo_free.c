/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:35:48 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/04 15:44:30 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void				free_list(t_elt *head)
{
	t_elt	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void				free_links(t_graph *g)
{
	int		i;

	i = 0;
	while (i < g->nbr_verts)
	{
		free_list(g->verts[i].list);
		i++;
	}
}
