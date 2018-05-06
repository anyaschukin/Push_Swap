/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 00:22:01 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 00:22:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_sb(t_frame *frame)
{
	long int	tmp;

	if (frame->b && frame->b->next != frame->b)
	{
		tmp = frame->b->num;
		frame->b->num = frame->b->next->num;
		frame->b->next->num = tmp;
	}
}
