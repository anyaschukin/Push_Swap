/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:16:04 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/01 17:23:29 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_stack_len(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	t_stack	*end;
	int		len;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	len = 0;
	if (stack)
		end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	while (stack)
	{
		len++;
		if (stack == end)
			break ;
		stack = stack->next;
	}
	return (len);
}
