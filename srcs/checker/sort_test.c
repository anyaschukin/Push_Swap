/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:28:03 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/10 14:41:18 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_test(t_frame *frame)
{
	t_stack		*stack_a;
	int			error;

	stack_a = frame->a;
	error = (frame->b) ? 1 : 0;
	while (stack_a && stack_a->next != frame->a)
	{
		if (stack_a->num > stack_a->next->num)
			error = 1;
		stack_a = stack_a->next;
	}
	if (error)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
