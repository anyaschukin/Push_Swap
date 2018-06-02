/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:39:14 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/02 13:51:48 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#');
}

int			ft_check_flags(t_print *arg)
{
	while (is_flag(arg->format[arg->i]))
	{
		arg->format[arg->i] == '-' ? DASH = 1 : 0;
		arg->format[arg->i] == '+' ? PLUS = 1 : 0;
		arg->format[arg->i] == '0' ? ZERO = 1 : 0;
		arg->format[arg->i] == ' ' ? SPACE = 1 : 0;
		arg->format[arg->i] == '#' ? HASH = 1 : 0;
		arg->i++;
	}
	return (arg->i);
}
