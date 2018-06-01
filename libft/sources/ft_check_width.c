/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:40:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/08 18:45:45 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_width(t_print *arg)
{
	int		multi;
	int		save;
	int		tmp;

	multi = 1;
	save = arg->i;
	tmp = 0;
	if (arg->format[arg->i] < '0' || arg->format[arg->i] > '9')
		return (arg->i);
	while (arg->format[arg->i] >= '0' && arg->format[arg->i] <= '9')
		arg->i++;
	WFIELD = 1;
	while (arg->i > save)
	{
		tmp++;
		arg->i--;
		WIDTH = WIDTH + (arg->format[arg->i] - 48) * multi;
		multi *= 10;
	}
	arg->i += tmp;
	if (WIDTH > INT_MAX || WIDTH <= 0)
		WIDTH = 0;
	return (arg->i);
}
