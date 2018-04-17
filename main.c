/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/17 18:36:10 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_clist		*astack;
	int			i;

	i = 1;
	astack = create_clist(astack, atoi(av[i++]));
	while (av[i])
	{
		add_to_end(astack, atoi(av[i++]));
	}
	printf("Stack A = %d, %d, %d, %d\n", astack->data, astack->next->data, astack->next->next->data,
			astack->next->next->next->data);
	return (0);
}
