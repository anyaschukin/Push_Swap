/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 23:59:31 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 07:19:47 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <stdio.h>

static void		check_duplicates(t_frame *frame)
{
	t_stack		*slow;
	t_stack		*fast;

	slow = frame->a;
	while (slow != frame->a->prev)
	{
		fast = slow->next;
		while (fast != frame->a)
		{
			if (slow->num == fast->num)
				push_swap_error(frame);
			fast = fast->next;
		}
		slow = slow->next;
	}
}

static void		complete_filling(t_frame *frame, char *str, int i, int j)
{
	long int	test_int_size;

	while (str)
	{
		while (*str)
		{
			while (!(j = 0) && *str && *str == ' ')
				str++;
			while (*(str + j) && (*(str + j) == '-' || *(str + j) == '+' ||
						ft_isdigit(*(str + j))))
				j++;
			if (j > 11)
				push_swap_error(frame);
			if (!*str)
				break ;
			test_int_size = ft_atoi_max(str);
			if (test_int_size > 2147483647 || test_int_size < -2147483648)
				push_swap_error(frame);
			stack_add_end(frame, 'a', test_int_size);
			str += j;
		}
		str = frame->argv[++i];
	}
}

static void		error_parser(t_frame *frame)
{
	char	*str;
	int		i;

	i = 1;
	str = frame->argv[i];
	while (str)
	{
		while (*str)
		{
			if (*str == ' ' || ft_isdigit(*str))
				str++;
			else if (*str == '-' && ft_isdigit(*(str + 1)) &&
						(str == frame->argv[i] || *(str - 1) == ' '))
				str++;
			else if (*str == '+' && ft_isdigit(*(str + 1)) &&
						(str == frame->argv[i] || *(str - 1) == ' '))
				str++;
			else
			{
				write(1, "H\n", 2);
				push_swap_error(frame);
			}
		}
		str = frame->argv[++i];
	}
}

void			fill_stack_a(t_frame *frame)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	str = frame->argv[i];
	error_parser(frame);
	complete_filling(frame, str, i, j);
	check_duplicates(frame);
}
