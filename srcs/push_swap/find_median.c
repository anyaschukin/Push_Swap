/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:46:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/14 16:34:55 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(long *array, int len) // replace with ft_sort_array from libft
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

/* Stores the stack in an array, sorts the array, and finds the median */

static long	find_median(t_frame *frame, t_stack *stack, char stack_name)
{
	long	*array;
	long	median;
	int		i;
	int		stack_len;
	int		half_len;

	i = 0;
	median = 0;
	stack_len = find_stack_len(frame, stack_name);
	half_len = stack_len / 2;
	if (!(array = (long*)malloc(sizeof(long) * stack_len + 1)))
		return (-1);
	while (i < stack_len)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	sort_array(array, stack_len);
	median = array[half_len];
	free(array);
	return (median);
}

long		median(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	return(find_median(frame, stack, stack_name));
}
