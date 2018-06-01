/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:29:58 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/13 15:43:14 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static long		atoi_push_swap(t_frame *frame, char *str)
{
	long	num;
	int		i;
	int		len;
	int		sign;

	num = 0;
	i = 0;
	len = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f')
		i++;
	str[i] == '-' ? (sign = -1) : 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		len++;
	}
	len > 10 ? push_swap_error(frame) : 0;
	return (num * sign);
}

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
			if (!*str)
				break ;
			test_int_size = atoi_push_swap(frame, str);
			if (test_int_size > 2147483647 || test_int_size < -2147483648)
				push_swap_error(frame);
			stack_add_end(frame, 'a', test_int_size);
			str += j;
		}
		str = frame->argv[++i];
	}
	if (!frame->a)
		push_swap_error(frame);
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
				push_swap_error(frame);
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
	j = 0;
	if (ft_strcmp(frame->argv[i], "-v") == 0)
	{
		frame->argv++;
		frame->print_stacks = 1;
	}
	str = frame->argv[i];
	error_parser(frame);
	complete_filling(frame, str, i, j);
	check_duplicates(frame);
}
