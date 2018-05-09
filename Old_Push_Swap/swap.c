/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:08:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/05 21:21:47 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swaps the first two elements at the top of the stack
*/

void	swap(t_stack **head)
{
	t_stack *first;
	t_stack *second;

	first = *head;
	second = (*head)->next;
	if (first && second && *head != NULL)
	{
		if (first->prev) // Do we need this "if" ?
			first->prev->next = second;
		if (second->next) // Do we need this "if" ?
			second->next->prev = first;
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		*head = (*head)->prev;
	}
}

/*
void	sa(t_frame *astack)
{

	swap(astack);
}


void	sb(t_frame *bstack)
{
	swap(bstack);
}


void	ss(t_frame *astack, t_frame *bstack)
{
	sa(astack);
	sb(bstack);
}
*/
