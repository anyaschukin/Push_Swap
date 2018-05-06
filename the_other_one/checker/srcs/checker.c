/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:56:43 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 05:22:48 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Checker is launched by the main.
** fill_stack_a is called to fill stack a with argv.
** do_launch get command line arguments and executes the commands.
** sort_test tests for if stack a is sorted or not following push swap.
*/

void			checker(t_frame *frame)
{
	fill_stack_a(frame);
	display_stacks(frame);
	do_launch(frame);
	sort_test(frame);
	push_swap_free(frame);
}
