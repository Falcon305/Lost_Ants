/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:06:54 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/14 20:54:02 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		free_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = NULL;
	while (stack != NULL)
	{
		tmp = stack;
		(stack) = (stack)->next;
		free(tmp);
	}
	free(stack);
	stack = NULL;
}

void		init_p(t_path **head)
{
	*head = (t_path *)malloc(sizeof(t_path));
	if (*head == NULL)
		exit(EXIT_FAILURE);
	(*head)->len = -1;
	(*head)->reg = 0;
	(*head)->path = NULL;
	(*head)->next = NULL;
}

void		add_p(t_path **head, t_stack *path)
{
	t_path		*new;
	t_path		*tmp;

	tmp = *head;
	if (tmp->len == -1)
	{
		tmp->len = stack_len(path) - 2;
		tmp->reg = 0;
		tmp->path = path;
		tmp->next = NULL;
	}
	else
	{
		if (!(new = (t_path *)malloc(sizeof(t_path))))
			exit(EXIT_FAILURE);
		new->len = stack_len(path) - 2;
		new->reg = 0;
		new->path = path;
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		free_p(t_path *head)
{
	t_path *tmp;

	tmp = NULL;
	while (head != NULL)
	{
		tmp = head;
		if (tmp->path != NULL)
			free_stack(tmp->path);
		(head) = (head)->next;
		free(tmp);
	}
	free(head);
	head = NULL;
}
