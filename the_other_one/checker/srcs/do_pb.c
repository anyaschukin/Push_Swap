/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 00:46:59 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 00:47:37 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_pb(t_frame *frame)
{
	long int	tmp;

	if (frame->a)
	{
		tmp = frame->a->num;
		stack_del_top(frame, 'a');
		stack_add_top(frame, 'b', tmp);
	}
}
