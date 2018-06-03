/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:54:10 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/03 18:54:12 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_moves(t_frame *frame)
{
	BIGGEST = 0;
	BIG_ROTATE = 0;
	BIG_RROTATE = 0;
	BIG_FLAG = 0;
	SMALLEST = 0;
	SMALL_ROTATE = 0;
	SMALL_RROTATE = 0;
	SMALL_FLAG = 0;
}
