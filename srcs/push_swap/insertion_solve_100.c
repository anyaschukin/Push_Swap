/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve_100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:49:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/29 11:49:11 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	insertion_solve_100(t_frame *frame)
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
	//			push_biggest_smallest_to_a(frame);
            printf("WTH\n");
		}
		while (--frame->after_rotate)
			do_ra(frame);
	//	display_stacks(frame); //
		split++;
		if (split == 3)
			break;
	}
}