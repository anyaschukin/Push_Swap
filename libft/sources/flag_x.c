/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:14:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 14:52:09 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	length_x(va_list *ap, t_print *arg)
{
	if (arg->length == 1 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'O')
		return ((unsigned int)(va_arg(*ap, unsigned long long)));
	else if (arg->length == 2 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'O')
		return ((long long)((unsigned char)va_arg(*ap, int)));
	else if (arg->length == 3 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'O')
		return (((unsigned long long)(unsigned short int)va_arg(*ap, int)));
	else if (arg->length == 6)
		return ((unsigned long long)va_arg(*ap, unsigned long long));
	else if (arg->length == 7)
		return ((unsigned long long)va_arg(*ap, size_t));
	else if (arg->length == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else
		return (va_arg(*ap, uintmax_t));
}

void		flag_x(va_list *ap, t_print *arg)
{
	intmax_t	nb;
	intmax_t	len;
	t_out		out;

	nb = length_x(ap, arg);
	if (nb == 0 && PFIELD == 1)
	{
		out.value = ft_strdup("\0");
		HASH = 0;
	}
	else
		out.value = ft_utoa_base(nb, 16);
	len = ft_strlen(out.value);
	out.string = ft_strdup(out.value);
	if (*out.value != '0')
		out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	if (HASH == 1 && nb != 0 && (out.string[1] == '0') &&
			(!ft_strchr(out.string, 'x') || !ft_strchr(out.string, 'X')))
		out.string[1] = 'x';
	CONV == 'x' ? ft_strtolower(out.string) :
		ft_strtoupper(out.string);
	ft_putstr(out.string);
	ft_strdel(out.value);
	ft_strdel(out.string);
}
