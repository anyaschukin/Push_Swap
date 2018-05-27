/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:29:30 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/08 12:29:31 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sb(t_frame *frame)
{
	long int	tmp;

	if (frame->b && frame->b->next != frame->b)
	{
		tmp = frame->b->num;
		frame->b->num = frame->b->next->num;
		frame->b->next->num = tmp;
	}
	if (frame->do_write)
		write(1, "sb\n", 3);
}
