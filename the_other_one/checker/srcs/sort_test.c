/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 04:47:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 05:59:42 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_test(t_frame *frame)
{
	t_stack		*tmp;

	tmp = frame->a;
	while (tmp->next != frame->a)
	{
		if (tmp->num > tmp->next->num)
		{
			write(1, "KO\n", 3);
			exit(-1);
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
}
