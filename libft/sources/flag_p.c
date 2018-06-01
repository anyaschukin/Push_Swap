/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:46:48 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 17:57:27 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static uintmax_t	length_p(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'X')
		return ((unsigned char)va_arg(*ap, uintmax_t));
	else if (arg->length == 3 && arg->format[arg->i] != 'X')
		return ((unsigned short int)va_arg(*ap, uintmax_t));
	else if (arg->length == 5 || arg->format[arg->i] == 'X')
		return ((unsigned long)va_arg(*ap, uintmax_t));
	else if (arg->length == 6)
		return ((unsigned long long)va_arg(*ap, uintmax_t));
	else if (arg->length == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (arg->length == 7)
		return ((size_t)va_arg(*ap, uintmax_t));
	else
		return (va_arg(*ap, uintmax_t));
}

void				flag_p(va_list *ap, t_print *arg)
{
	uintmax_t	nb;
	intmax_t	len;
	t_out		out;

	nb = length_p(ap, arg);
	out.value = (nb == 0 && PFIELD == 1) ? ft_strdup("\0") :
		ft_utoa_base(nb, 16);
	if (WFIELD == 1 && ZERO != 1)
		if (!(out.value = ft_strjoin_free("0x", out.value, 2)))
			error_exit(ERROR, 1);
	len = ft_strlen(out.value);
	out.string = ft_strdup(out.value);
	out.string = combine(arg, &out, len);
	if (!(ft_strstr(out.string, "0x")))
		if (!(out.string = ft_strjoin_free("0x", out.string, 2)))
			error_exit(ERROR, 1);
	arg->ret += ft_strlen(out.string);
	ft_strtolower(out.string);
	ft_putstr(out.string);
	ft_strdel(out.value);
	ft_strdel(out.string);
}
