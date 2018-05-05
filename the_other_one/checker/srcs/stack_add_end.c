/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 20:55:10 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/05 20:55:23 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		stack_add_end(t_frame *frame, char c, int num)
{
	t_stack		**top;
	t_stack		*tmp;

	DEBUG("%s\n", "  STACK_ADD_END");//////////
	if (c == 'a')
		top = &frame->a;
	else if (c == 'b')
		top = &frame->b;
	else
		write(1, "Whoa!\n", 6);

	DEBUG("Value of TOP[%p]\n", *top);//////////
	if (*top)
	{
		DEBUG("%s\n", "Inside first if. 1");//////////
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			push_swap_exit(frame);
		DEBUG("%s\n", "Inside first if. 2");//////////
		tmp->next = *top;
		DEBUG("%s\n", "Inside first if. 3");//////////
		tmp->prev = (*top)->prev;
		DEBUG("%s\n", "Inside first if. 4");//////////
		(*top)->prev = tmp;
		DEBUG("%s\n", "Inside first if. 5");//////////
		tmp->prev->next = tmp;
		DEBUG("%s\n", "Inside first if. 6");//////////
		tmp->num = num;
		DEBUG("%s\n", "Inside first if. 7");//////////
	}
	else
	{
		DEBUG("%s\n", "Inside second if. 1");//////////
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			push_swap_exit(frame);
		DEBUG("%s\n", "Inside second if. 2");//////////
		(*top)->next = *top;
		DEBUG("%s\n", "Inside second if. 3");//////////
		(*top)->prev = *top;
		DEBUG("%s\n", "Inside second if. 4");//////////
		(*top)->num = num;
		DEBUG("%s\n", "Inside second if. 5");//////////
	}
}
