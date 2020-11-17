/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:33:44 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/09 14:18:56 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		ft_free_cap(t_graph *g)
{
	int i;

	i = 0;
	while (i < g->nbr_verts)
	{
		if (g->cap[i] != NULL)
			free(g->cap[i]);
		i++;
	}
	if (g->cap != NULL)
		free(g->cap);
	g->cap = NULL;
}

int			main(void)
{
	t_data	*head;
	t_graph g;

	head = NULL;
	if (ft_parsing_data(&g, &head) == -1)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	if (start_end(&g))
	{
		ft_print_list(head);
		print_special(&g);
	}
	else
	{
		build_list(&g);
		fill_capacity(&g);
		output(&g, g.start, g.end, head);
		ft_free_cap(&g);
	}
	ft_free_struct_pars(&g, head);
	return (0);
}
