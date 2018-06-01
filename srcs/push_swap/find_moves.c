/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:32:39 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/01 17:06:19 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculates number of moves to top of stack
*/

void		moves_to_start(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? frame->a : frame->b;
		element = (flag == 1) ? SMALLEST : BIGGEST;
		while (tmp->num != element)
		{
			flag == 1 ? SMALL_ROTATE++ : BIG_ROTATE++;
			tmp = tmp->next;
		}
	}
}

/*
** Calculates moves to bottom of stack
*/

void		moves_to_end(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
		element = (flag == 1) ? SMALLEST : BIGGEST;
		while (tmp->num != element)
		{
			flag == 1 ? SMALL_RROTATE++ : BIG_RROTATE++;
			tmp = tmp->prev;
		}
		flag == 1 ? SMALL_RROTATE++ : BIG_RROTATE++;
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
		if (SMALL_ROTATE <= SMALL_RROTATE)
			SMALL_RROTATE = -1;
		else
			SMALL_ROTATE = -1;
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
		if (BIG_ROTATE <= BIG_RROTATE)
			BIG_RROTATE = -1;
		else
			BIG_ROTATE = -1;
	}
}

/*
** Calculates which has fewest moves to push to stack a:
** the biggest or smallest integer in stack b,
** either by rotating to the top or reverse rotating to the end.
*/

void		find_moves(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
	if (BIG_ROTATE != -1 && (BIG_ROTATE >= SMALL_ROTATE &&
		BIG_ROTATE >= SMALL_RROTATE))
		BIG_ROTATE = -1;
	else if (BIG_RROTATE != -1 && (BIG_RROTATE >= SMALL_ROTATE &&
		BIG_RROTATE >= SMALL_RROTATE))
		BIG_RROTATE = -1;
	else if (SMALL_ROTATE != -1 && (SMALL_ROTATE >= BIG_ROTATE &&
		SMALL_ROTATE >= BIG_RROTATE))
		SMALL_ROTATE = -1;
	else if (SMALL_RROTATE != -1 && (SMALL_RROTATE >= BIG_ROTATE &&
		SMALL_RROTATE >= BIG_RROTATE))
		SMALL_RROTATE = -1;
	if (SMALL_ROTATE != -1 || SMALL_RROTATE != -1)
		SMALL_FLAG = 1;
	else if (BIG_ROTATE != -1 || BIG_RROTATE != -1)
		BIG_FLAG = 1;
}
