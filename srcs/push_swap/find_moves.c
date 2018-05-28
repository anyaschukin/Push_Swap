/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:32:39 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/23 16:39:47 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates number of moves to top of stack */

static void	moves_to_start(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? frame->a : frame->b;
		element = (flag == 1) ? frame->smallest : frame->biggest;
		while (tmp->num != element)
		{
			flag == 1 ? frame->small_rotate++ : frame->big_rotate++;
			tmp = tmp->next;
		}
	}
}

/* Calculates moves to bottom of stack */

static void	moves_to_end(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
		element = (flag == 1) ? frame->smallest : frame->biggest;
		while (tmp->num != element)
		{
			flag == 1 ? frame->small_rrotate++ : frame->big_rrotate++;
			tmp = tmp->prev;
		}
		flag == 1 ? frame->small_rrotate++ : frame->big_rrotate++;
	}
}

static void	moves_smallest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	flag = 1;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (frame->small_rotate <= frame->small_rrotate)
			frame->small_rrotate = -1;
		else
			frame->small_rotate = -1;
	}
}

static void	moves_biggest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	flag = 2;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (frame->big_rotate <= frame->big_rrotate)
			frame->big_rrotate = -1;
		else
			frame->big_rotate = -1;
	}
}

/*
 ** Calculates which has fewest moves to push to stack a:
 ** the biggest or smallest integer in stack b,
 ** either by rotating to the top or reverse rotating to the end.
 */

void	find_moves(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
	if (frame->big_rotate != -1 && (frame->big_rotate >= frame->small_rotate && frame->big_rotate >= frame->small_rrotate))
		frame->big_rotate = -1;
	else if (frame->big_rrotate != -1 && (frame->big_rrotate >= frame->small_rotate && frame->big_rrotate >= frame->small_rrotate))
		frame->big_rrotate = -1;
	else if (frame->small_rotate != -1 && (frame->small_rotate >= frame->big_rotate && frame->small_rotate >= frame->big_rrotate))
		frame->small_rotate = -1;
	else if (frame->small_rrotate != -1 && (frame->small_rrotate >= frame->big_rotate && frame->small_rrotate >= frame->big_rrotate))
		frame->small_rrotate = -1;
	if (frame->small_rotate != -1 || frame->small_rrotate != -1) 
		frame->small_flag = 1;
	else if (frame->big_rotate != -1 || frame->big_rrotate != -1) 
		frame->big_flag = 1;
}






