/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:58:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/14 13:12:05 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_frame *frame)
{
	int med;

	fill_stack_a(frame);
	if (sorted(frame))
	{
		push_swap_free(frame);
		return ;
	}
	display_stacks(frame);
	med = median(frame, 'a');
	push_median(frame, med);
	display_stacks(frame);
//	if (!sorted(frame))
//		algorithm(frame);
//	push_swap_error(frame);
}
