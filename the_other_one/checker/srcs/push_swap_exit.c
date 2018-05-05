/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:14:39 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/05 02:50:19 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		free_stack(t_stack *stack)
{
	t_stack		*track_next;
	t_stack		*delete;

	if (stack)
	{
		track_next = stack->next;
		while (track_next != stack)
		{
			delete = track_next;
			track_next = track_next->next;
			free(delete);
		}
		free(track_next);
	}
}

static void		free_frame(t_frame *frame)
{
	if (frame)
	{
		if (frame->a)
			free_stack(frame->a);
		if (frame->b)
			free_stack(frame->b);
		free(frame);
	}
}

void			push_swap_exit(t_frame *frame)
{
	write(1, "Error\n", 6);
	free_frame(frame);
	exit(-1);
}
