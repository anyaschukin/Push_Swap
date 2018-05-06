/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:40:32 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 05:05:22 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Main creates frame to hold stack a and stack b by caling create_frame.
*/

int		main(int argc, char **argv)
{
	t_frame		*frame;

	frame = NULL;
	if (argc < 2)
		push_swap_error(frame);
	frame = create_frame(frame, argc, argv);
	checker(frame);
	return (0);
}
