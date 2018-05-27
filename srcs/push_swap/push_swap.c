/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:58:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/16 16:22:18 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_frame *frame)
{
	int med;

	fill_stack_a(frame);
	frame->do_write = 1;
	if (!sorted(frame))
	{
		solver(frame);
		return ;
	}
//	med = median(frame, 'a');
//	push_median(frame, med);
//	if (!sorted(frame))
//		algorithm(frame);
//	push_swap_error(frame);
}
