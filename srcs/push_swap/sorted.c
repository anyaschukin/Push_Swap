/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:59:41 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/10 12:56:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_frame *frame)
{
	t_stack		*tmp;

	if (!frame->a || frame->b)
		return (0);
	tmp = frame->a;
	while (tmp->next != frame->a)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
