/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:32:03 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/14 16:38:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_median_etc(t_frame *frame, char stack_name, long median)
{
// if bigger than 1/2 median, push to top of B
// if smaller than 1/2 median, push to bottom of B

	t_stack	*stack;
	int		flag;

	stack = frame->a;
}


/* Pushes every number below median into Stack b */

void	push_median(t_frame *frame, long median)
{
	t_stack	*stack;
	t_stack	*stack_a_end;
	int		flag;
	int		*top;

	stack = frame->a;
	stack_a_end = frame->a->prev;
	flag = 0;
	while (1)
	{
		if (stack == stack_a_end)
			flag = 1;
		if (stack->num <= median)
			do_pb(frame);
		else
			do_ra(frame);
		if (flag == 1)
			break;
		stack = frame->a;
	}
}
	
	
	
	/*
	while (1)
	{
		if (stack == frame->a->prev)
			flag = 1;
		if (stack->num <= median)
		{
			while (frame->a->num > median) // rotate until frame->a->num == top
				do_ra(frame);
			do_pb(frame);
			stack = frame->a;
		}
		else if (flag == 1)
			break;
		else
			stack = stack->next;
	}
}*/
