/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:02:06 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 18:33:18 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	weird_case_one(va_list *ap, t_print *arg, t_out *out)
{
	char		c;

	if (!(c = va_arg(*ap, intmax_t)))
		c = '\0';
	out->value = ft_strnew(1);
	out->value[0] = CONV;
	CONV = 'c';
}

static void	weird_case_two(t_out *out)
{
	out->value = ft_strdup("R");
}

static void	big_c(va_list *ap, t_out *out)
{
	wchar_t		w;

	w = va_arg(*ap, wchar_t);
	out->value = ft_unicode(w);
	if (out->value == NULL)
		out->value = ft_strdup(("(null)"));
}

static void	small_c(va_list *ap, t_out *out)
{
	char		c;

	if (!(c = va_arg(*ap, intmax_t)))
		c = '\0';
	out->value = ft_strnew(1);
	out->value[0] = c;
}

void		flag_c(va_list *ap, t_print *arg)
{
	intmax_t	len;
	t_out		out;

	if (CONV != 'c' && CONV != 'C' && CONV != '%' && CONV != 'R')
		weird_case_one(ap, arg, &out);
	else if (CONV == 'R')
		weird_case_two(&out);
	else if (arg->length == 5 || CONV == 'C')
		big_c(ap, &out);
	else
		small_c(ap, &out);
	len = ft_strwlen(out.value);
	out.string = ft_strdup(out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	len == 0 ? arg->ret += 1 : 0;
	len == 0 ? ft_putnstr(out.string) : 0;
	len > 0 ? ft_putstr(out.string) : 0;
	ft_strdel(out.value);
	ft_strdel(out.string);
}
