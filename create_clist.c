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
	t_clist	*root;

	tmp = root;
	if (!(root = (t_clist*)malloc(sizeof(*root))))
			return (NULL);
	if (root)
	{
		root->prev = NULL;
		root->next = NULL;
		root->data = data;
	}
	return (root);
}

void	add_to_head(t_clist *root, int data) // THIS WORKS!!
{
	t_clist *new;

	new = (t_clist*)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->data = data;
		new->next = root->next;
		new->prev = root;
		if (root->next == root)
		{
			root->next = new;
			root->prev = new;
		}
		else
		{
			root->next = new;
			root->next->prev = new;
		}
	}
}

void	add_to_end(t_clist *root, int data) // THIS WORKS!!
{
	t_clist *new;

	new = (t_clist*)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->data = data;
		new->next = root;
		new->prev = (root->next) ? root->prev : root;
		root->prev = new;
		new->prev->next = new;
	}
}
