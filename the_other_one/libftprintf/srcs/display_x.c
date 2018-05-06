/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:30:17 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 20:53:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static void			print_leading_zero(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	get_num(t_tab *tab)
{
	uintmax_t	num;

	if (ft_strcmp(tab->argument_flag, "hh") == 0)
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

static t_tab		*do_x(t_tab *tab, uintmax_t num, char *str, int align_left)
{
	int			n_b;
	int			n_w;

	if ((n_w = ft_strlen(str)) && tab->convert[4] == '#' && num &&
			tab->convert[3] == '0' && tab->field_width)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && tab->convert[4] == '#' && num)
	{
		tab->field_width -= 2;
		tab->len += 2;
	}
	n_b = (n_w <= tab->precision && tab->precision > 0) ? tab->precision : n_w;
	tab->len += (n_b <= tab->field_width) ? tab->field_width : n_b;
	if (!align_left)
		display_gap(tab, ' ', tab->field_width - n_b, 0);
	print_leading_zero(num, tab->convert[4], tab->specifier_flag);
	display_gap(tab, '0', tab->precision - n_w, 0);
	ft_putstr(str);
	if (align_left)
		display_gap(tab, ' ', tab->field_width - n_b, 0);
	return (tab);
}

t_tab				*display_x(t_tab *tab)
{
	char		*str;
	char		c;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		display_gap(tab, ' ', tab->field_width, 1);
		return (tab);
	}
	c = 'a';
	if (tab->specifier_flag == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	if (tab->convert[0] == '-')
		align_left = 1;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->field_width;
	do_x(tab, num, str, align_left);
	free(str);
	return (tab);
}
