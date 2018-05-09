/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:27:17 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/08 12:27:22 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

static t_table	do_launch_value(int execute_value)
{
	t_table		table[47];
	int			i;

	i = 0;
	while (i < 47)
		table[i++] = &push_swap_error;
	table[11] = &do_sa;
	table[14] = &do_sb;
	table[17] = &do_ss;
	table[20] = &do_pa;
	table[23] = &do_pb;
	table[26] = &do_ra;
	table[29] = &do_rb;
	table[32] = &do_rr;
	table[35] = &do_rra;
	table[39] = &do_rrb;
	table[43] = &do_rrr;
	return (table[execute_value]);
}

void			do_launch(t_frame *frame)
{
	static char		*str = NULL;
	char			*ptr;
	char			*line;
	int				execute_value;
	t_table			do_now;

	str = ft_strdup(" s a b p r sa sb ss pa pb ra rb rr rra rrb rrr");
	while ((get_next_line(0, &line)) == 1)
	{
		ptr = ft_strstr(str, line);
		execute_value = ptr - str;
		if (execute_value > 43 || execute_value < 0)
			push_swap_error(frame);
		free(line);
		do_now = do_launch_value(execute_value);
		do_now(frame);
		display_stacks(frame);
	}
	free(str);
}
