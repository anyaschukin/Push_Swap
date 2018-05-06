/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 23:52:11 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 05:03:23 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_frame		*create_frame(t_frame *frame, int argc, char **argv)
{
	if (!(frame = (t_frame *)malloc(sizeof(t_frame))))
		push_swap_error(frame);
	frame->a = NULL;
	frame->b = NULL;
	frame->argc = argc;
	frame->argv = argv;
	return (frame);
}
