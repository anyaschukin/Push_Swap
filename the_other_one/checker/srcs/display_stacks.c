/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 01:21:15 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 05:58:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"

void		display_stacks(t_frame *frame)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = frame->a;
	stack_b = frame->b;
	ft_printf("%15s   %-15s\n", "Stack A", "Stack B");
	while (stack_a != frame->a->prev)
	{
		ft_printf("%15d | %-15d\n", stack_a->num, stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("%15d | %-15d\n", stack_a->num, stack_a->num);
}
