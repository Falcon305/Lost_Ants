/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:22:07 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/14 20:53:32 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int						paths_len(t_path *path)
{
	int len;

	len = 0;
	while (path)
	{
		if (path->path != NULL)
			len++;
		path = path->next;
	}
	return (len);
}

int						nodes_num(t_path *path)
{
	int nodes;

	nodes = 0;
	while (path)
	{
		if (path->path != NULL)
			nodes += path->len;
		path = path->next;
	}
	return (nodes);
}

void					init_g(t_group **head)
{
	*head = (t_group *)malloc(sizeof(t_group));
	if (*head == NULL)
		exit(EXIT_FAILURE);
	(*head)->score = -1;
	(*head)->n_paths = 0;
	(*head)->n_verts = 0;
	(*head)->path = NULL;
	(*head)->next = NULL;
}

void					add_g(t_group **head, t_path *path, t_graph *g)
{
	t_group		*new;
	t_group		*tmp;

	tmp = *head;
	if (tmp->score == -1)
	{
		tmp->n_paths = paths_len(path);
		tmp->n_verts = nodes_num(path);
		tmp->score = calc_score(g, tmp->n_paths, tmp->n_verts);
		tmp->path = path;
		tmp->next = NULL;
	}
	else
	{
		if (!(new = (t_group *)malloc(sizeof(t_group))))
			exit(EXIT_FAILURE);
		new->n_paths = paths_len(path);
		new->n_verts = nodes_num(path);
		new->score = calc_score(g, new->n_paths, new->n_verts);
		new->path = path;
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void					free_g(t_group *head)
{
	t_group *tmp;

	tmp = NULL;
	while (head != NULL)
	{
		tmp = head;
		if (tmp->path != NULL)
			free_p(tmp->path);
		(head) = (head)->next;
		free(tmp);
	}
	free(head);
	head = NULL;
}
