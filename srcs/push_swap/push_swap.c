/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:58:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/10 13:31:57 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_frame *frame)
{
	fill_stack_a(frame);
	if (sorted(frame))
	{
		push_swap_free(frame);
		return ;
	}
	display_stacks(frame);
	push_swap_error(frame);
}
