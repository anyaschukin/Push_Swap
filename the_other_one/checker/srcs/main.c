/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:40:32 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/05 03:46:54 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Main creates frame to hold stack a and stack b by caling create_frame.
*/

int		main(int argc, char **argv)
{
	t_frame		*frame;

	DEBUG("%s\n", "   MAIN.");//////////
	frame = NULL;
	DEBUG("%s\n", "frame assigned null");//////////
	if (argc < 2)
		push_swap_exit(frame);
	frame = create_frame(frame, argc, argv);
	DEBUG("%s\n", "frame created");//////////
	checker(frame);
	DEBUG("%s\n", "   MAIN END");//////////
	return (0);
}
