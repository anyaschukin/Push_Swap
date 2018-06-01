/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:06:02 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/08 18:42:46 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_s(va_list *ap, t_print *arg)
{
	wchar_t		*wstr;
	char		*str;
	intmax_t	len;
	t_out		out;

	if (arg->length == 5 || arg->format[arg->i] == 'S')
	{
		wstr = va_arg(*ap, wchar_t *);
		out.value = ft_strunicode(wstr);
		out.value == NULL ? out.value = ft_strdup(("(null)")) : 0;
	}
	else
	{
		str = va_arg(*ap, char *);
		str == NULL ? str = ("(null)") : 0;
		out.value = ft_strdup(str);
	}
	len = ft_strwlen(out.value);
	out.string = ft_strdup(out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	ft_putstr(out.string);
	ft_strdel(out.string);
	ft_strdel(out.value);
}
