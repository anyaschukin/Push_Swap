/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:01:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 10:06:30 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static t_tab	*display_percent(t_tab *tab)
{
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		tab->field_width = 0;
	}
	if (tab->convert[0] != '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	if (tab->convert[3] == '0')
		display_gap(tab, '0', tab->precision - 1, 1);
	write(1, "%", 1);
	if (tab->convert[0] == '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	tab->len++;
	return (tab);
}

t_tab			*display_other(t_tab *tab)
{
	if (tab->f_treat[tab->i] == '%')
	{
		display_percent(tab);
		return (tab);
	}
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		tab->field_width = 0;
	}
	if (tab->convert[0] != '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	if (tab->convert[3] == '0')
		display_gap(tab, '0', tab->precision - 1, 1);
	write(1, &tab->f_copy[tab->i], 1);
	if (tab->convert[0] == '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	tab->len++;
	return (tab);
}
