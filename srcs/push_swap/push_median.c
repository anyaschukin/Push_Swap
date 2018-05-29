/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:32:03 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/25 12:19:23 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes every number above or below median into Stack b, based on split flag */

void	push_median(t_frame *frame, int split)
{
	t_stack	*stack;
	t_stack	*stack_a_end;
	int		flag; 
	// add an int "len" to keep track of what I've already sorted, that way I don't
	// rotate past a huge stack of sorted numbers to get to the unsorted

	stack = frame->a;
	stack_a_end = frame->a->prev;
	flag = 0;
	while (1)
	{
		if (stack == stack_a_end)
			flag = 1;
		if (split == 1 && stack->num <= frame->median)
			do_pb(frame);
		else if (split == 2 && stack->num > frame->median) // push according to 1/2 median?
			do_pb(frame);
		else if (split == 2 && stack->num == frame->smallest)
			break;
		else
			do_ra(frame);
		if (flag == 1)
			break;
		stack = frame->a;
	}
}