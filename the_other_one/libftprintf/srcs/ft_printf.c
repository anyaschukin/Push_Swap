/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:52:37 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 20:28:05 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	tab = initialize(tab);
	if (format)
	{
		va_start(tab->args, format);
		tab->len = parser(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->len);
}
