/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/05 21:03:19 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			i;
	t_stack		*res;

	i = 1;
	while (ac > 1)
	{
		while (av[i])
		{
			res = parser(av[i++]);
			swap(&res);
			printf("Stack A = %d, %d, %d, %d, %d\n", res->data, res->next->data, res->next->next->data, res->next->next->next->data, res->next->next->next->next->data);
		printf((check_duplicate(res) == 1) ? "OK\n" : "KO\n");
		if (check_duplicate(res) == 1)
			printf("There are no duplicates\n");
		}
		ac--;
	}
	/*
	astack = create_clist(astack, atoi(av[i++]));
	while (av[i])
	{
		add_to_tail(astack, atoi(av[i++]));
	}
	printf("Stack A = %d, %d, %d, %d\n", astack->data, astack->next->data, astack->next->next->data,
			astack->next->next->next->data);
	return (0);
	*/
}
