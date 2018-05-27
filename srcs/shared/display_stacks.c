/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:26:53 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/09 17:20:24 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

static void	free_strings(char *a, char *b)
{
	free(a);
	free(b);
}

static void display_printf(t_frame *frame, int a_flag, int b_flag)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*a;
	char		*b;

	stack_a = frame->a;
	stack_b = frame->b;

	a_flag = (!stack_a) ? 1 : 0;
	b_flag = (!stack_b) ? 1 : 0;
	while (1)
	{
		a = (!a_flag) ? ft_itoa(stack_a->num) : ft_strdup("");//protect malloc
		b = (!b_flag) ? ft_itoa(stack_b->num) : ft_strdup("");//protect malloc
		a_flag = (!stack_a || stack_a == frame->a->prev) ? 1 : 0;
		b_flag = (!stack_b || stack_b == frame->b->prev) ? 1 : 0;
		(!stack_a && !stack_b) ? free_strings(a, b) : 0;
		if ((!stack_a && !stack_b))
			break ;
		ft_printf("%15s | %-15s\n", a, b);
		free_strings(a, b);
		stack_a = (stack_a && stack_a != frame->a->prev) ? stack_a->next : NULL;
		stack_b = (stack_b && stack_b != frame->b->prev) ? stack_b->next : NULL;
	}
}

void		display_stacks(t_frame *frame)
{
	// if -v on command line, trigger usleep function
	usleep(100000); // this is a number of microseconds
	ft_printf("\E[H\E[2J"); // escape sequence to clear screen
	ft_printf("%15s   %-15s\n", "Stack A", "Stack B");
	display_printf(frame, 0, 0);	
}
