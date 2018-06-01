/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:26:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/21 16:25:14 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame		*create_frame(t_frame *frame, char **argv)
{
	if (!(frame = (t_frame *)malloc(sizeof(t_frame))))
		exit(1);
	frame->a = NULL;
	frame->b = NULL;
	frame->argv = argv;
	frame->line = NULL;
	frame->str = NULL;
	frame->print_stacks = 0;
	frame->do_write = 0;
	frame->stack_len = 0;
	QUARTER = 0;
	MEDIAN = 0;
	THREE_Q = 0;
	BIGGEST = 0;
	BIG_ROTATE = 0;
	BIG_RROTATE = 0;
	BIG_FLAG = 0;
	SMALLEST = 0;
	SMALL_ROTATE = 0;
	SMALL_RROTATE = 0;
	SMALL_FLAG = 0;
	frame->after_rotate = 0;
	return (frame);
}
