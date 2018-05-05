/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:44:48 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/29 00:11:35 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*parse_arguments(t_tab *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab->argument_mask[i] != '\0')
	{
		while (tab->argument_mask[i] == tab->f_treat[tab->i])
		{
			tab->argument_flag[j] = tab->f_treat[tab->i];
			tab->argument_flag[j + 1] = '\0';
			tab->i++;
			j++;
		}
		i++;
	}
	return (tab);
}
