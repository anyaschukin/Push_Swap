/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:50:07 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/05 20:53:34 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

// TODO check all digits, spaces, look for duplicates

int		check_duplicate(t_clist *head)
{
	t_clist *tmp1;
	t_clist	*tmp2;

	tmp1 = head;
	while (tmp1 != NULL && tmp1->next != head)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL && tmp2 != head)
		{
			if (tmp2->data == tmp1->data)
			{
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

t_clist	*parser(char *str)
{
	t_clist	*astack;
	size_t	test;
	long	tmp;
	int		i;
	long	j;

	i = 0;
	astack = NULL;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' && ft_isdigit(str[i + 1]) &&
				(i == 0 || str[i - 1] == ' '))
			i++;
		else if (str[i] == '+' && ft_isdigit(str[i + 1]) &&
				(i == 0 || str[i - 1] == ' '))
			i++;
		else
			error_exit("Error\n", 1);
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		while (str[i + j] != '\0' && (str[i + j] == '-' ||
					str[i + j] == '+' || ft_isdigit(str[i + j])))
		{
			j++;
			if (j > 11)
				error_exit("Error\n", 1);
		}
		if (str[i] == '\0')
			break;
		tmp = ft_atoi_long(str + i);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_exit("Error\n", 1);
		if (!astack)
			astack = create_clist(astack, tmp);
		else
			add_to_tail(astack, tmp);
		str = str + j;
	}
	return (astack);
}
