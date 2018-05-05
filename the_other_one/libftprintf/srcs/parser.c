/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:54:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 09:55:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	parser(t_tab *tab)
{
	if (ft_strcmp(tab->f_copy, "%") == 0)
		return (0);
	while (tab->f_copy[tab->i] != '\0')
	{
		if (tab->f_copy[tab->i] == '%')
		{
			reinitialize(tab);
			treatement(tab);
		}
		else
		{
			write(1, &tab->f_copy[tab->i], 1);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
