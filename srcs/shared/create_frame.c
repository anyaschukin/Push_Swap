/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:26:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/16 16:46:23 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame		*create_frame(t_frame *frame, int argc, char **argv)
{
	if (!(frame = (t_frame *)malloc(sizeof(t_frame))))
		 exit(1); // removed push_swap_error to remove chance of segfault
	frame->a = NULL;
	frame->b = NULL;
	frame->argc = argc;
	frame->argv = argv;
	frame->line = NULL;
	frame->str = NULL;
	frame->biggest = 0;
	frame->smallest = 0;
	return (frame);
}
