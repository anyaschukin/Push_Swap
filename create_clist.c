/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_clist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:20:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/04 14:48:06 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Create + add to a Circular linked list
*/

t_clist*	create_clist(t_clist *tmp, int data)
{
	t_clist	*head;

	tmp = head;
	if (!(head = (t_clist*)malloc(sizeof(*head))))
			return (NULL);
	if (head)
	{
		head->prev = NULL;
		head->next = NULL;
		head->data = data;
	}
	return (head);
}

void	add_to_top(t_clist *head, int data) // THIS WORKS!!
{
	t_clist *new;

	new = (t_clist*)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->data = data;
		new->next = head->next;
		new->prev = head;
		if (head->next == head)
		{
			head->next = new;
			head->prev = new;
		}
		else
		{
			head->next = new;
			head->next->prev = new;
		}
	}
}

void	add_to_tail(t_clist *head, int data) // THIS WORKS!!
{
	t_clist *new;

	new = (t_clist*)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->data = data;
		new->next = head;
		new->prev = (head->next) ? head->prev : head;
		head->prev = new;
		new->prev->next = new;
	}
}
