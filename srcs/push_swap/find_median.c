/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:46:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/13 18:55:11 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int len) // replace with ft_sort_array from libft
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < len - 1)
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

/*
 ** Stores the stack in an array, sorts the array, and finds the median
 */

int			find_median(t_frame *frame, t_stack *stack, char stack_name)
{
	int	*array;
	int	i;
	int	stack_len;
	int	half_len;
	int	median;

	i = 0;
	median = 0;
	stack_len = find_stack_len(frame, stack_name);
	half_len = stack_len / 2;
	if (!(array = (int*)malloc(sizeof(int) * stack_len + 1)))
		return (-1);
	while (i++ < stack_len)
	{
		array[i] = stack->num;
		stack = stack->next;
	}
	sort_array(array, stack_len);
	median = array[half_len];
	free(array);
	return (median);
}

int		median(t_frame *frame, char stack_name)
{
	t_stack *stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	return(find_median(frame, stack, stack_name));
}
