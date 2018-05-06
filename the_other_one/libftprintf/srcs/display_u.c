/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 00:41:03 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 10:02:26 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static uintmax_t	get_num(t_tab *tab)
{
	uintmax_t	num;

	if (tab->specifier_flag == 'U')
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else if (ft_strcmp(tab->argument_flag, "hh") == 0)
		num = (unsigned char)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->argument_flag, "h") == 0)
		num = (unsigned short)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->argument_flag, "ll") == 0)
		num = (unsigned long long)(va_arg(tab->args, unsigned long long int));
	else if (ft_strcmp(tab->argument_flag, "l") == 0)
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else if (ft_strcmp(tab->argument_flag, "j") == 0)
		num = (uintmax_t)(va_arg(tab->args, uintmax_t));
	else if (ft_strcmp(tab->argument_flag, "z") == 0)
		num = (size_t)(va_arg(tab->args, size_t));
	else
		num = (unsigned int)(va_arg(tab->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static int			get_tens(uintmax_t num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_tab		*do_u(t_tab *tab, uintmax_t num, int num_width, int left)
{
	int			not_blank;

	not_blank = num_width;
	if (num_width <= tab->precision)
		not_blank = tab->precision;
	tab->len += (not_blank <= tab->field_width) ? tab->field_width : not_blank;
	if (!left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	display_gap(tab, '0', tab->precision - num_width, 0);
	ft_putnbrumax_fd(num, 1);
	if (left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	return (tab);
}

t_tab				*display_u(t_tab *tab)
{
	uintmax_t	num;
	int			num_width;
	int			left;

	left = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		display_gap(tab, ' ', tab->field_width, 1);
		return (tab);
	}
	num_width = get_tens(num);
	if (tab->convert[0] == '-')
		left = 1;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->field_width;
	do_u(tab, num, num_width, left);
	return (tab);
}
