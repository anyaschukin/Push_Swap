/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:32:39 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/21 18:14:05 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates number of moves to top of stack */

static void	moves_to_start(t_frame *frame, char stack_name) //
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;
	int		rotate;

	stack = (stack_name == 'a') ? frame->a : frame->b; //
	if (stack)
		tmp = (stack_name == 'a') ? frame->a : frame->b; // not sure start is needed
	element = frame->smallest ? frame->smallest : frame->biggest;
	frame->big_rotate = 0;
	while (tmp->num != element)
	{
		frame->big_rotate++;
		tmp = tmp->next;
	}
}

/* Calculates moves to bottom of stack */

static void	moves_to_end(t_frame *frame, char stack_name) //
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? frame->a : frame->b; //
	if (stack)
		tmp = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	element = frame->smallest ? frame->smallest : frame->biggest;
	frame->big_rrotate = 0; // this is necessary
	while (tmp->num != element)
	{
		frame->big_rrotate++; // this is why small_rrotate doesn't work
		tmp = tmp->prev;
	}
}

static void	moves_smallest(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		moves_to_start(frame, stack_name);
		moves_to_end(frame, stack_name);
		if (frame->small_rotate <= frame->small_rrotate)
			frame->small_rrotate = 0;
		else
			frame->small_rotate = 0;
	}
}

static void	moves_biggest(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b; //
	if (stack)
	{
		moves_to_start(frame, stack_name);
		moves_to_end(frame, stack_name);
		if (frame->big_rotate <= frame->big_rrotate)
			frame->big_rrotate = 0;
		else
			frame->big_rotate = 0;
	}
}

/*
 ** Calculates which has fewest moves to push to stack a:
 ** the biggest or smallest integer in stack b,
 ** either by rotating to the top or reverse rotating to the end.
 */

void	find_moves(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		big;
	int		small;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
}






