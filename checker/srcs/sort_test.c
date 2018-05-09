/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:28:03 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/09 11:28:04 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_test(t_frame *frame)
{
	t_stack		*tmp;
	int			error;

	tmp = frame->a;
	error = (frame->b) ? 1 : 0;
	while (tmp->next != frame->a)
	{
		if (tmp->num > tmp->next->num)
			error = 1;
		tmp = tmp->next;
	}
	if (error)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
