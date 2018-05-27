/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:29:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/08 12:29:22 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_frame *frame)
{
	long int	tmp;

	if (frame->a && frame->a->next != frame->a)
	{
		tmp = frame->a->num;
		frame->a->num = frame->a->next->num;
		frame->a->next->num = tmp;
	}
	if (frame->do_write)
		write(1, "sa\n", 3);
}
