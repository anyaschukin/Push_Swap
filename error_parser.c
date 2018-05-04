/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:50:07 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/04 17:51:02 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

// check all digits, spaces, look for duplicates

t_clist	*parser(char *str)
{
	t_clist *astack;
	size_t test;
	int i;
	int j;
	
	i = 0;
	j = 0;
	astack = NULL;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' && ft_isdigit(str[i + 1]) && (i != 0 && str[i - 1] == ' '))
			i++;
		else if (str[i] == '+' && ft_isdigit(str[i + 1]) && (i != 0 && str[i - 1] == ' '))
			i++;
		else
			error_exit("Error\n", 1);
	}
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i] == ' ')
			i++;
		while (str[i + j] == '-' || str[i + j] == '+' || ft_isdigit(str[i + j]))
		{
			j++;
			if (j > 11)
				error_exit("Error\n", 1);
		}
		if (!astack)
			astack = create_clist(astack, ft_atoi(str + i));
		else
			add_to_tail(astack, ft_atoi(str + i));
		str = str + j;
	}
	return (astack);
}
