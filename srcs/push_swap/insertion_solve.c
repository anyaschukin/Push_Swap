/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:46:51 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/23 16:38:18 by aschukin         ###   ########.fr       */
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
			while (stack->num != frame->biggest)
				stack = stack->next;
			if (stack->num == frame->biggest)
			{
				if (frame->big_rotate >= 0)
					while (frame->big_rotate--)
					{
						do_rb(frame);
						write(1, "rb\n", 3);
					}
				else if (frame->big_rrotate >= 0)
					while (frame->big_rrotate--)
					{	do_rrb(frame);
						write(1, "rrb\n", 4); }
				do_pa(frame);
				write(1, "pa\n", 3);
				break;
			}
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
			while (stack->num != frame->smallest)
				stack = stack->next;
			if (stack->num == frame->smallest)
			{
				if (frame->small_rotate >= 0)
					while (frame->small_rotate--)
					{
						do_rb(frame);
						write(1, "rb\n", 3); }
				else if (frame->small_rrotate >= 0)
					while (frame->small_rrotate--)
					{
						do_rrb(frame);
						write(1, "rrb\n", 4);  }
				do_pa(frame);
				write(1, "pa\n", 3);
				break;
			}
			else
				stack = stack->next;
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
	printf("median %ld\n", median);
	printf("smallest %ld\n", frame->smallest);
	printf("biggest %ld\n", frame->biggest);
	find_moves(frame, 'b');
	if (stack && (frame->small_rotate >= 0 || frame->small_rrotate >= 0))
		push_smallest_to_a(frame, 'b');
	else if (stack && (frame->big_rotate >= 0 || frame->big_rrotate >= 0))
		push_biggest_to_a(frame, 'b');
	display_stacks(frame); //
}
