/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_smallest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:42:36 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/17 15:01:32 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the biggest and smallest integers in the stack that is called */

static void	find_smallest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	if (stack)
		end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	frame->smallest = frame->biggest;
	while (1)
	{
		if (tmp->num <= frame->smallest)
			frame->smallest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

static void	find_biggest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	if (stack)
		end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	while (1)
	{
		if (tmp->num >= frame->biggest)
			frame->biggest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void		find_biggest_smallest(t_frame *frame, char stack_name)
{
	t_stack		*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	find_biggest(frame, 'b');
	find_smallest(frame, 'b');
}
