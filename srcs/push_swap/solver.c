/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:12:44 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/25 12:18:49 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_frame *frame)
{
	if (!(sorted(frame)))
	{
	//	if (find_stack_len(frame, 'a') <= 100)
			insertion_solve(frame);
	//	else
	//		insertion_solve_100(frame);
	}
//	display_stacks(frame);
}