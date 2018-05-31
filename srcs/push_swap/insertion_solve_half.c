/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve_half.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:31:43 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/31 15:31:46 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	reset_moves(t_frame *frame)
{
	frame->biggest = 0;
	frame->big_rotate = 0;
	frame->big_rrotate = 0;
	frame->big_flag = 0;
	frame->smallest = 0;
	frame->small_rotate = 0;
	frame->small_rrotate = 0;
	frame->small_flag = 0;
}

/* Pushes biggest or smallest from stack B to stack A, in sorted order */

static void	push_biggest_smallest_to_a(t_frame *frame, t_stack *stack, t_stack *stack_end) // not normed
{
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

/* Finds stack A's median
** Pushes everything above/below median into stack B
** Identifies biggest + smallest
** Whichever one is fewer moves gets pushed to stack A
** Pushes smallest to the end of A
** Pushes biggest to the top of A
*/

void	insertion_solve_half(t_frame *frame)
{
	int	split;

	split = 1;
	median(frame, 'a');	
	while (frame->a)
	{
		push_median(frame, split);
		display_stacks(frame); //
		while (frame->b)
		{
			find_biggest_smallest(frame, 'b');
			find_moves(frame, 'b');
			if (frame->b && (frame->small_rotate >= 0 || frame->small_rrotate >= 0 
				|| frame->big_rotate >= 0 || frame->big_rrotate >= 0))
				push_biggest_smallest_to_a(frame, frame->b, frame->b->prev);
			display_stacks(frame); //
		}
		while (--frame->after_rotate)
			do_ra(frame);
		display_stacks(frame); //
		split++;
		if (split == 3)
			break;
	}
}
