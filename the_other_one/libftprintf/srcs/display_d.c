/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:44:21 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 09:59:55 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static intmax_t	get_num(t_tab *tab)
{
	intmax_t	num;

	if (tab->specifier_flag == 'D')
		num = (long)(va_arg(tab->args, long int));
	else if (ft_strcmp(tab->argument_flag, "hh") == 0)
		num = (signed char)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->argument_flag, "h") == 0)
		num = (short)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->argument_flag, "ll") == 0)
		num = (long long)(va_arg(tab->args, long long int));
	else if (ft_strcmp(tab->argument_flag, "l") == 0)
		num = (long)(va_arg(tab->args, long int));
	else if (ft_strcmp(tab->argument_flag, "j") == 0)
		num = (intmax_t)(va_arg(tab->args, intmax_t));
	else if (ft_strcmp(tab->argument_flag, "z") == 0)
		num = (size_t)(va_arg(tab->args, size_t));
	else
		num = (int)(va_arg(tab->args, int));
	num = (intmax_t)num;
	return (num);
}

static int		get_tens(intmax_t num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_negatvity_placeholder(t_tab *tab, int is_negative)
{
	char	*tmp;

	tmp = tab->convert;
	if (is_negative)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

static t_tab	*do_d(t_tab *tab, intmax_t num, int num_width, int align_left)
{
	int			not_blank;
	char		negatvity_placeholder;
	int			is_negative;

	is_negative = (num < 0) ? 1 : 0;
	num *= (is_negative && num != (-9223372036854775807 - 1)) ? -1 : 1;
	negatvity_placeholder = get_negatvity_placeholder(tab, is_negative);
	not_blank = num_width;
	if (num_width <= tab->precision && tab->precision >= 0)
		not_blank = tab->precision;
	if (negatvity_placeholder)
		not_blank++;
	tab->len += (not_blank <= tab->field_width) ? tab->field_width : not_blank;
	if (!align_left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	if (negatvity_placeholder)
		write(1, &negatvity_placeholder, 1);
	display_gap(tab, '0', tab->precision - num_width, 0);
	if (num != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(num, 1);
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (align_left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	return (tab);
}

t_tab			*display_d(t_tab *tab)
{
	intmax_t	num;
	int			num_width;
	int			align_left;

	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		if (tab->convert[1] == '+')
			display_wchar('+', tab);
		if (tab->convert[2] == ' ')
			display_wchar(' ', tab);
		display_gap(tab, ' ', tab->field_width, 1);
		return (tab);
	}
	num_width = get_tens(num);
	align_left = (tab->convert[0] == '-') ? 1 : 0;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		if (num < 0 || tab->convert[2] || tab->convert[1] || tab->convert[0])
			tab->precision--;
	}
	do_d(tab, num, num_width, align_left);
	return (tab);
}
