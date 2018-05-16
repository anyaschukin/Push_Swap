/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:46:51 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/16 18:46:41 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// start with 1/2 in stack a, 1/2 in stack b
// push median to top of stack a
// push smallest to stack a, then ra so smallest is in the back
// always keep the median at the top of stack a

static void	push_smallest_to_a(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	t_stack *stack_b_end;
	
	stack = frame->b;
	if (stack)
		stack_b_end = frame->b->prev;
	while (1)
	{
		if (stack->num == frame->smallest)
		{
			do_pa(frame);
			do_ra(frame);
		}
		else
			do_rb(frame);
		if (stack == stack_b_end)
			break;
		stack = frame->b;
	}
}

/* Puts the median of both stacks at the top of stack A */

static void	median_top_a(t_frame *frame, char stack_name, long median)
{
	t_stack	*stack;
	t_stack	*stack_b_end;

	stack = frame->b;
	if (stack)
		stack_b_end = frame->b->prev;
	while (1)
	{
		if (stack->num == median)
			do_pa(frame);
		else
			do_rb(frame);
		if (stack == stack_b_end)
			break;
		stack = frame->b;
	}
}

void	insertion_solve(t_frame *frame, char stack_name, long median)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	display_stacks(frame); //
	median_top_a(frame, 'b', median);
	find_biggest_smallest(frame, 'b');
	push_smallest_to_a(frame, 'b');
	printf("%ld\n", median);
	printf("%ld\n", frame->smallest);
}
