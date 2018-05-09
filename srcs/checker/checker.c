/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:25:49 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/08 12:26:01 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
