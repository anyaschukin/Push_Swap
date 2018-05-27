/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:27:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/09 17:21:35 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_frame *frame)
{
	long int	tmp;

	if (frame->b)
	{
		tmp = frame->b->num;
		stack_del_top(frame, 'b');
		stack_add_top(frame, 'a', tmp);
	}
	if (frame->do_write)
		write(1, "pa\n", 3);
}
