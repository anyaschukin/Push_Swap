/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve_half.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:31:43 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/01 18:23:20 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pushes biggest or smallest from stack B to stack A, in sorted order
*/

static void	rotate_and_push_to_a(t_frame *frame)
{
	if (SMALL_ROTATE >= 0)
		while (SMALL_ROTATE--)
			do_rb(frame);
	else if (SMALL_RROTATE >= 0)
		while (SMALL_RROTATE--)
			do_rrb(frame);
	else if (BIG_ROTATE >= 0)
		while (BIG_ROTATE--)
			do_rb(frame);
	else if (BIG_RROTATE >= 0)
		while (BIG_RROTATE--)
			do_rrb(frame);
	do_pa(frame);
	SMALL_FLAG ? do_ra(frame) : 0;
	(BIG_FLAG || !frame->b) ? frame->after_rotate++ : 0;
	reset_moves(frame);
}

static void	push_big_small(t_frame *frame, t_stack *stack, t_stack *stack_end)
{
	while (1)
	{
		while (stack->num != SMALLEST && stack->num != BIGGEST)
			stack = stack->next;
		if (stack->num == SMALLEST || stack->num == BIGGEST)
		{
			rotate_and_push_to_a(frame);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = frame->b;
	}
}

/*
** Finds stack A's median
** Pushes everything above/below median into stack B
** Identifies biggest + smallest
** Whichever one is fewer moves gets pushed to stack A
** Pushes smallest to the end of A
** Pushes biggest to the top of A
*/

void		insertion_solve_half(t_frame *frame)
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
			if (frame->b && (SMALL_ROTATE >= 0 || SMALL_RROTATE >= 0
				|| BIG_ROTATE >= 0 || BIG_RROTATE >= 0))
				push_big_small(frame, frame->b, frame->b->prev);
		}
		while (--frame->after_rotate)
			do_ra(frame);
		split++;
		if (split == 3)
			break ;
	}
}
