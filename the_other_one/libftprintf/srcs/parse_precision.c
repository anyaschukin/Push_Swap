/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:45:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 00:16:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_precision(t_tab *tab)
{
	while (tab->f_treat[tab->i] == '.')
	{
		tab->i++;
		tab->precision = 0;
	}
	while (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
	{
		tab->precision *= 10;
		tab->precision += (tab->f_treat[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}
