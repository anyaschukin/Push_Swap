/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:38:45 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/08 18:45:00 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_precision(t_print *arg)
{
	int		multi;
	int		save;
	int		tmp;

	multi = 1;
	tmp = 0;
	arg->format[arg->i] == '.' ? PFIELD = 1 : 0;
	arg->format[arg->i] == '.' ? arg->i++ : 0;
	save = arg->i;
	while (arg->format[arg->i] >= '0' && arg->format[arg->i] <= '9')
		arg->i++;
	while (arg->i > save)
	{
		tmp++;
		arg->i--;
		PREC = PREC + (arg->format[arg->i] - 48) * multi;
		multi *= 10;
	}
	arg->i += tmp;
	if (PREC > INT_MAX || (int)PREC < 0)
	{
		PFIELD = -1;
		PREC = 0;
	}
	return (arg->i);
}
