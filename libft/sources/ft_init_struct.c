/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:50:18 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/08 18:46:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_pstruct(t_print *arg)
{
	CONV = 0;
	DASH = 0;
	PLUS = 0;
	ZERO = 0;
	SPACE = 0;
	HASH = 0;
	WFIELD = 0;
	WIDTH = 0;
	PFIELD = 0;
	PREC = 0;
	arg->length = 1;
	arg->ispositive = 0;
	arg->isnegative = 0;
}

void	ft_init_ostruct(t_out *out)
{
	out->string = NULL;
	out->value = NULL;
	out->vlen = 0;
}

void	ft_init_struct(t_print *arg, t_out *out)
{
	ft_init_pstruct(arg);
	ft_init_ostruct(out);
}
