/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 01:30:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 20:51:22 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static void			print_leading_zero(uintmax_t num, char hash)
{
	if (hash == '#' && num)
		write(1, "0", 1);
}

static uintmax_t	get_num(t_tab *tab)
{
	uintmax_t	num;

	if (tab->specifier_flag == 'O')
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

static t_tab		*print_u(t_tab *tab, uintmax_t num, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (tab->convert[4] == '#' && num)
		num_width++;
	not_blank = num_width;
	if (num_width <= tab->precision && tab->precision > 0)
		not_blank = tab->precision;
	tab->len += (not_blank <= tab->field_width) ? tab->field_width : not_blank;
	if (!left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	print_leading_zero(num, tab->convert[4]);
	display_gap(tab, '0', tab->precision - num_width, 0);
	ft_putstr(str);
	free(str);
	if (left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	return (tab);
}

t_tab				*display_o(t_tab *tab)
{
	char		*str;
	uintmax_t	num;
	int			left;

	left = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0 && tab->convert[4] != '#')
	{
		display_gap(tab, ' ', tab->field_width, 1);
		return (tab);
	}
	if (!(str = ft_itoa_base(num, 8, 'a')))
		exit(-1);
	if (tab->convert[0] == '-')
		left = 1;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->field_width;
	print_u(tab, num, str, left);
	return (tab);
}
