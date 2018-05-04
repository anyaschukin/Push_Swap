/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:50:07 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/04 15:41:34 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check all digits, spaces, look for duplicates

int	parser(char *str)
{
	t_clist *astack;
	int i;
	
	i = 0;
	while (str[i++])
	{
		if (str[0] == ' ' || !ft_isdigit(str[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	i = 0;
	while (str[i])
	{
		ft_atoi(str + i);
		while (str[i] != ' ' || str[i] != '\0')
			i++;
	}

		
}
