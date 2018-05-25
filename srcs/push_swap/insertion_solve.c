/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:46:51 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/25 13:39:33 by aschukin         ###   ########.fr       */
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

static void sort_top_a(t_frame *frame)
{
	t_stack	*stack;
	t_stack *tmp;

	stack = frame->a;
	tmp = stack->next;
	while (stack->num < tmp->num)
	{
		do_sa(frame);
		stack = stack->next;
		tmp = tmp->next;
		write(1,"WTF\n", 4);
	}
}

static void	push_biggest_smallest_to_a(t_frame *frame, char stack_name) //
{
	t_stack	*stack;
	t_stack *stack_end;

	stack = frame->b;
	stack_end = frame->b->prev;
	while (1)
	{
		while (stack->num != frame->smallest && stack->num != frame->biggest)
			stack = stack->next;
		if (stack->num == frame->smallest || stack->num == frame->biggest)
		{
			if (frame->small_rotate >= 0)
				while (frame->small_rotate--)
					do_rb(frame);
			else if (frame->small_rrotate >= 0)
				while (frame->small_rrotate--)
					do_rrb(frame);
			else if (frame->big_rotate >= 0)
				while (frame->big_rotate--)
					do_rb(frame);
			else if (frame->big_rrotate >= 0) 
				while (frame->big_rrotate--)
					do_rrb(frame);		
			do_pa(frame);
			do_sa(frame);
			break;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break;
		stack = frame->b;
	}
}

/* Puts the median of both stacks at the top of stack A */

static void	median_top_a(t_frame *frame, char stack_name) //
{
	t_stack	*stack;
	t_stack	*stack_b_end;

	stack = frame->b;
	if (stack)
	{
		stack_b_end = frame->b->prev;
		while (1)
		{
			if (stack->num == frame->median)
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

void	insertion_solve(t_frame *frame, char stack_name)
{
//	t_stack	*stack;

//	stack = (stack_name == 'a') ? frame->a : frame->b; // necessary?
	median_top_a(frame, 'b');
	display_stacks(frame); //
	while (frame->b)
	{
		reset_moves(frame);
		find_biggest_smallest(frame, 'b');
		printf("median %ld\n", frame->median);
		printf("smallest %ld\n", frame->smallest);
		printf("biggest %ld\n", frame->biggest);
		find_moves(frame, 'b');
		if (frame->b && (frame->small_rotate >= 0 || frame->small_rrotate >= 0 || frame->big_rotate >= 0 || frame->big_rrotate >= 0))
			push_biggest_smallest_to_a(frame, stack_name);
		sort_top_a(frame);
		display_stacks(frame); //
	}
}
