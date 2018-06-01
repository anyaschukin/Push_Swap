/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 15:08:38 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_conversion(va_list *ap, t_print *arg)
{
	CONV = arg->format[arg->i];
	arg->format[arg->i] == 'C' ? flag_c(ap, arg) : 0;
	arg->format[arg->i] == 'c' ? flag_c(ap, arg) : 0;
	arg->format[arg->i] == 'd' ? flag_d(ap, arg) : 0;
	arg->format[arg->i] == 'D' ? flag_d(ap, arg) : 0;
	arg->format[arg->i] == 'i' ? flag_d(ap, arg) : 0;
	arg->format[arg->i] == 'o' ? flag_o(ap, arg) : 0;
	arg->format[arg->i] == 'O' ? flag_o(ap, arg) : 0;
	arg->format[arg->i] == 'p' ? flag_p(ap, arg) : 0;
	arg->format[arg->i] == 's' ? flag_s(ap, arg) : 0;
	arg->format[arg->i] == 'S' ? flag_s(ap, arg) : 0;
	arg->format[arg->i] == 'u' ? flag_u(ap, arg) : 0;
	arg->format[arg->i] == 'U' ? flag_u(ap, arg) : 0;
	arg->format[arg->i] == 'x' ? flag_x(ap, arg) : 0;
	arg->format[arg->i] == 'X' ? flag_x(ap, arg) : 0;
	arg->format[arg->i] == '%' ? flag_percent(arg) : 0;
	arg->format[arg->i] == 'R' ? flag_c(ap, arg) : 0;
	!(ft_strchr("cCdDioOpsSuUxX%R", arg->format[arg->i])) ? flag_c(ap, arg) : 0;
	arg->i++;
	return (arg->i);
}
