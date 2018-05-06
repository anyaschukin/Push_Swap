/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:23:03 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/15 19:30:29 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_clist	*tmp;
	
	if (!tmp)
		create_clist(tmp);
	if (ac <= 1)
		error_exit("Error\n", 1); // needs to display nothing
	else
	{
		while (*av++)
		{
			if (ft_isdigit((long long)*av) != 1)
				error_exit("Error\n", 1);
			if ((long long)*av < INT_MIN || (long long)*av > INT_MAX)
				error_exit("Error\n", 1);

		}
	}
}
