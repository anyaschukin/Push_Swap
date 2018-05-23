/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:46:51 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/22 16:16:19 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// start with 1/2 in stack a, 1/2 in stack b
// push median to top of stack a
// push smallest to stack a, then ra so smallest is in the back
// always keep the median at the top of stack a

/* Pushes the biggest in stack B to stack A */

static void	reset_moves(t_frame *frame)
{
	frame->biggest = 0;
	frame->smallest = 0;
	frame->big_rotate = 0;
	frame->big_rrotate = 0;
	frame->small_rotate = 0;
	frame->small_rrotate = 0;
}

static void	push_biggest_to_a(t_frame *frame, char stack_name) //
{
	t_stack	*stack;
	t_stack *stack_end;

	stack = frame->b;
	if (stack)
	{
		stack_end = (stack_name == 'a') ? frame->a->prev : frame->b->prev; //
		while (1)
		{
			if (stack->num == frame->biggest)
			{
				if (frame->big_rotate >= 0)
					while (frame->big_rotate--)
						do_rb(frame);
				else if (frame->big_rrotate >= 0)
					while (frame->big_rrotate--)
						do_rrb(frame);
				do_pa(frame);
			}
			else
				do_rb(frame);
			if (stack == stack_end)
				break;
			stack = frame->b;
		}
	}
}

/* Pushes the smallest in stack B to stack A */

static void	push_smallest_to_a(t_frame *frame, char stack_name) //
{
	t_stack	*stack;
	t_stack *stack_end;

	stack = frame->b;
	if (stack)
	{
		stack_end = (stack_name == 'a') ? frame->a->prev : frame->b->prev; //
		while (1)
		{
			if (stack->num == frame->smallest)
			{
				if (frame->small_rotate >= 0)
					while (frame->small_rotate--)
						do_rb(frame);
				else if (frame->small_rrotate >= 0)
					while (frame->small_rrotate--)
						do_rrb(frame);
				do_pa(frame);
			}
			else
				do_rb(frame);
			if (stack == stack_end)
				break;
			stack = frame->b;
		}
	}
}

/* Puts the median of both stacks at the top of stack A */

static void	median_top_a(t_frame *frame, char stack_name, long median) //
{
	t_stack	*stack;
	t_stack	*stack_b_end;

	stack = frame->b;
	if (stack)
	{
		stack_b_end = frame->b->prev;
		while (1)
		{
			if (stack->num == median)
			{
				while (frame->big_rotate-- >= 1)
					do_rb(frame);
				while (frame->big_rrotate-- >= 1)
					do_rrb(frame);
				do_pa(frame);
			}
			else
				do_rb(frame);
			if (stack == stack_b_end)
				break;
			stack = frame->b;
		}
	}
}

// find smallest + biggest, whichever one is less moves to top a gets pushed

void	insertion_solve(t_frame *frame, char stack_name, long median)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b; // necessary?
	median_top_a(frame, 'b', median);
	display_stacks(frame); //
	reset_moves(frame);
	find_biggest_smallest(frame, 'b');
	find_moves(frame, 'b');
	printf("small_rotate %d\n", frame->small_rotate);
	printf("small_rrotate %d\n", frame->small_rrotate);
	printf("big_rotate %d\n", frame->big_rotate);
	printf("big_rrotate %d\n", frame->big_rrotate);
	if (stack && (frame->small_rotate >= 0 || frame->small_rrotate >= 0))
		push_smallest_to_a(frame, 'b');
	else if (stack && (frame->big_rotate >= 0 || frame->big_rrotate >= 0))
		push_biggest_to_a(frame, 'b');
	printf("median %ld\n", median);
	printf("smallest %ld\n", frame->smallest);
	printf("biggest %ld\n", frame->biggest);
	display_stacks(frame); //
}
