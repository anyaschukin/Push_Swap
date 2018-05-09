/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:28:24 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/09 11:28:26 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_add_top(t_frame *frame, char stack_name, int num)
{
	t_stack		**top;
	t_stack		*tmp;

	top = (stack_name == 'a') ? &frame->a : &frame->b;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			push_swap_error(frame);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->num = num;
		*top = (*top)->prev;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			push_swap_error(frame);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->num = num;
	}
}
