/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:56:43 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/05 23:35:43 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Main passes argv to checker only if argc is greater than 1/
** Checker asks get_arg_list to return a valid s_args.
*/

void			checker(t_frame *frame)
{
	DEBUG("%s\n", "   CHECKER.");//////////
	fill_stack_a(frame);
	DEBUG("%s\n", "returned to checker from fill_stack_a");//////////
	if (frame->a)
		printf("Stack a [%ld] [%ld] [%ld] [%ld] \n", frame->a->num, frame->a->next->num, frame->a->next->next->num, frame->a->next->next->next->num);
}
