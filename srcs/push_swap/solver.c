/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:12:44 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/21 17:45:40 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds median
// pushes everything below median into stack b
// identifies biggest + smallest
// push smallest to the end of A
// push biggest to the front of A
// sorts stack b

void	solver(t_frame *frame)
{
	int	stack_median;

	if (!(sorted(frame)))
	{
		stack_median = median(frame, 'a');
		push_median(frame, stack_median);
		insertion_solve(frame, 'b', stack_median);
	}
//	display_stacks(frame);
}
