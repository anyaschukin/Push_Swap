/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:55:14 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 03:12:48 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		treatement(t_tab *tab)
{
	tab->i++;
	parse_convert(tab);
	parse_field_width(tab);
	parse_precision(tab);
	parse_arguments(tab);
	parse_specifier(tab);
	switch_display(tab);
	return (tab->len);
}
