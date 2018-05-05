/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 23:59:31 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/05 17:36:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

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
						(i == 0 || *(str - 1) == ' '))
				str++;
			else if (*str == '+' && ft_isdigit(*(str + 1)) &&
						(i == 0 || *(str - 1) == ' '))
				str++;
			else
				push_swap_exit(frame);
		}
		str = frame->argv[++i];
	}
}

void			fill_stack_a(t_frame *frame)
{
	char	*str;
	int		i;
	int		j;

	DEBUG("%s\n", "   FILL_STACK_A.");//////////
	i = 1;
	str = frame->argv[i];
	error_parser(frame);
	while (str)
	{
	DEBUG("%s\n", "while 1");//////////
		while (*str)
		{
		DEBUG("%s\n", "while 2");//////////
			//DEBUG("Str is [%s]\n", str);//////////
			while (!(j = 0) && *str && *str == ' ')
				str++;
			while (*(str + j) && (*(str + j) == '-' || *(str + j) == '+' ||
						ft_isdigit(*(str + j))))
				j++;
			if (j > 11)
				push_swap_exit(frame);
			if (!*str)
				break ;
			DEBUG("%s\n", "Above stack_add");//////////
			stack_add_end(frame, 'a', ft_atoi(str));//amend ATOI.
			DEBUG("%s\n", "Below stack_add");//////////
			str += j;
		}
		i++;
		DEBUG("Value of i[%d]\n", i);//////////
		str = frame->argv[i];
	}
}
