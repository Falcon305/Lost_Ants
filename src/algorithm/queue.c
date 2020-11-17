/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:53:05 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/14 20:54:18 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_queue				*queue_create(void)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	if (!q)
		exit(EXIT_FAILURE);
	q->tail = 0;
	q->head = q->tail;
	return (q);
}

void				enq(t_queue *q, int value)
{
	t_elt	*e;

	e = (t_elt *)malloc(sizeof(t_elt));
	if (!e)
		exit(EXIT_FAILURE);
	e->value = value;
	e->next = 0;
	if (q->head == 0)
		q->head = e;
	else
		q->tail->next = e;
	q->tail = e;
}

int					queue_empty(const t_queue *q)
{
	return (q->head == 0);
}

int					deq(t_queue *q)
{
	int		ret;
	t_elt	*e;

	ret = q->head->value;
	e = q->head;
	q->head = e->next;
	free(e);
	return (ret);
}

int					queue_destroy(t_queue *q)
{
	while (!queue_empty(q))
		deq(q);
	free(q);
	return (1);
}
