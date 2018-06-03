/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:32:03 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/01 17:24:08 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pushes every number above or below median into Stack b, based on split flag
*/

void	push_median(t_frame *frame, int split)
{
	t_stack	*stack;
	t_stack	*stack_a_end;
	int		flag;

	stack = frame->a;
	stack_a_end = frame->a->prev;
	flag = 0;
	find_smallest(frame, 'a');
	while (1)
	{
		if (stack == stack_a_end)
			flag = 1;
		if (split == 1 && stack->num <= MEDIAN)
			do_pb(frame);
		else if (split == 2 && stack->num > MEDIAN)
			do_pb(frame);
		else if (stack->num == SMALLEST)
			break ;
		else
			do_ra(frame);
		if (flag == 1)
			break ;
		stack = frame->a;
	}
	reset_moves(frame);
}
