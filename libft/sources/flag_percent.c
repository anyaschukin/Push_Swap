/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:14:45 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 16:10:55 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_percent(t_print *arg)
{
	intmax_t	len;
	t_out		out;

	out.value = ft_strdup("%");
	PFIELD == 1 ? PFIELD = 0 : 0;
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
