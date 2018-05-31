/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5_or_less.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:24:11 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/31 15:24:16 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	solve_3(t_frame *frame)
{
    t_stack *stack_a;
    t_stack *tmp;

    find_biggest(frame, 'a');
    moves_to_end(frame, 'a', 2);
    if (frame->big_rrotate >= 1) 
	    while (frame->big_rrotate-- > 1)
	        do_rra(frame);
    stack_a = frame->a;
    tmp = frame->a->next;
    if (stack_a->num > tmp->num)
        do_sa(frame);
}

static void	solve_5(t_frame *frame)
{
    t_stack *stack_b;
    t_stack *tmp;

	frame->median = 1;
	push_median(frame, 1);
    solve_3(frame);
    stack_b = frame->b;
    tmp = frame->b->next;
    if (frame->b->num < tmp->num)
        do_sb(frame);
    do_pa(frame);
    do_pa(frame);
}
 
void	solve_5_or_less(t_frame *frame)
{
    if (find_stack_len(frame, 'a') <= 3) // 2 , 4 
        solve_3(frame);
    else if (find_stack_len(frame, 'a') <= 5)
        solve_5(frame);
}
