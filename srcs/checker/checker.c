/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:25:49 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/01 17:22:50 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checker is launched by the main.
** fill_stack_a is called to fill stack A with argv.
** do_launch gets command line arguments and executes the commands.
** sort_test tests for if stack A is sorted or not following Push_Swap.
*/

void	checker(t_frame *frame)
{
	fill_stack_a(frame);
	do_launch(frame);
	sort_test(frame);
	push_swap_free(frame);
}

/*
** Main creates frame to hold stack A and stack B by calling create_frame.
*/

int		main(int argc, char **argv)
{
	t_frame		*frame;

	frame = NULL;
	if (argc < 2)
		return (1);
	frame = create_frame(frame, argv);
	checker(frame);
	return (0);
}
