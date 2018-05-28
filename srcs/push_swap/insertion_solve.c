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

static void	reset_moves(t_frame *frame)
{
	frame->biggest = 0;
	frame->smallest = 0;
	frame->big_rotate = 0;
	frame->big_rrotate = 0;
	frame->big_flag = 0;
	frame->small_rotate = 0;
	frame->small_rrotate = 0;
	frame->small_flag = 0;
}

/* Pushes biggest or smallest from stack B to stack A, in sorted order */

static void	push_biggest_smallest_to_a(t_frame *frame) // not normed
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
			frame->small_flag ? do_ra(frame) : 0;
			(frame->big_flag || !frame->b) ? frame->after_rotate++ : 0;
			reset_moves(frame);
			break;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break;
		stack = frame->b;
	}
}



/* finds smallest + biggest, whichever one is less moves to top A gets pushed to stack A */

void	insertion_solve(t_frame *frame)
{
	int	split;

	split = 1;
	median(frame, 'a');	
	while (frame->a)
	{
		push_median(frame, split);
		while (frame->b)
		{
			find_biggest_smallest(frame, 'b');
			find_moves(frame, 'b');
			if (frame->b && (frame->small_rotate >= 0 || frame->small_rrotate >= 0 
				|| frame->big_rotate >= 0 || frame->big_rrotate >= 0))
				push_biggest_smallest_to_a(frame);
		}
		while (frame->after_rotate--)
			do_ra(frame);
	//	display_stacks(frame); //
		split++;
		if (split == 3)
			break;
	}
}

/*
static void	smallest_to_top_a(t_frame *frame) // not normed
{
	t_stack	*stack;
	t_stack *stack_end;

	stack = frame->a;
	stack_end = frame->a->prev;
	find_biggest_smallest(frame, 'a');
	find_moves(frame, 'a');
	while (1)
	{
		while (stack->num != frame->smallest && stack->num != frame->biggest)
			stack = stack->next;
		if (stack->num == frame->smallest || stack->num == frame->biggest)
		{
			if (frame->small_rotate >= 0)
				while (frame->small_rotate--)
					do_ra(frame);
			else if (frame->small_rrotate >= 0)
				while (frame->small_rrotate--)
					do_rra(frame);
			else if (frame->big_rotate >= 0)
				while (frame->big_rotate--)
					do_ra(frame);
			else if (frame->big_rrotate >= 0) 
				while (frame->big_rrotate--)
					do_rra(frame);		
		//	frame->big_flag ? do_ra(frame) : 0; // if biggest && stack->a, then ra
			reset_moves(frame);
			break;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break;
		stack = frame->a;
	}
}*/

/*
static void	smallest_top_a(t_frame *frame)
{
	t_stack	*stack;
	t_stack	*stack_a_end;

	stack = frame->a;
	reset_moves(frame);
	find_biggest_smallest(frame, 'a');
	find_moves(frame, 'a'); // won't work if big_rotate is smaller than small_rotate
	stack_a_end = frame->a->prev;
	while (1)
	{
		if (stack->num == frame->smallest || stack->num == frame->biggest)
		{
			while (frame->small_rotate-- >= 0)
				do_ra(frame);
			while (frame->small_rrotate-- >= 0)
				do_rra(frame);
		}
//		else
//			do_ra(frame);
		if (stack == stack_a_end)
			break;
		stack = frame->a;
	}
}*/

		//	printf("median %ld\n", frame->median);
		//	printf("smallest %ld\n", frame->smallest);
		//	printf("biggest %ld\n", frame->biggest);

/* Puts the median of both stacks at the top of stack A */

/*
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
}*/