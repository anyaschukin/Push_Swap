/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_clist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:20:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/05 15:46:35 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Create + add to a Circular linked list
 */

t_stack*	create_clist(t_stack *tmp, int data)
{
	t_stack	*head;

	tmp = head;
	if (!(head = (t_stack*)malloc(sizeof(*head))))
		return (NULL);
	if (head)
	{
		head->prev = head;
		head->next = head;
		head->data = data;
	}
	return (head);
}

void	add_to_top(t_stack *head, int data) // THIS WORKS!!
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(*new));
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

void	add_to_tail(t_stack *head, int data) // THIS WORKS!!
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(*new))))
		error_exit("Error\n", 1);
	new->data = data;
	new->next = head;
	new->prev = (head->next == head) ? head : head->prev;
	head->prev = new;
	new->prev->next = new;
}
