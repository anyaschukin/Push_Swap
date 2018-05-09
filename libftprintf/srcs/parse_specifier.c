/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:45:37 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 00:16:53 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_specifier(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->specifier_mask[i] != '\0')
	{
		if (tab->specifier_mask[i] == tab->f_treat[tab->i])
			tab->specifier_flag = tab->specifier_mask[i];
		i++;
	}
	return (tab);
}
