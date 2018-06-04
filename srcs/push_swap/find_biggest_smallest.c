/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_smallest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:42:36 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/01 17:03:51 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the biggest and smallest integers in the stack that is called
*/

void	find_smallest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	SMALLEST = BIGGEST;
	while (1)
	{
		if (tmp->num <= SMALLEST)
			SMALLEST = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	BIGGEST = tmp->num;
	end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	while (1)
	{
		if (tmp->num > BIGGEST)
			BIGGEST = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest_smallest(t_frame *frame, char stack_name)
{
	t_stack		*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	find_biggest(frame, stack_name);
	find_smallest(frame, stack_name);
}
