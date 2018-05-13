/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:23:39 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/13 18:25:37 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_array(int *array, int len)
{
	int i;
	int swap;

	i = 0;
	swap = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			swap = array[i];
			array[i] = array[i + 1];
			array[i + 1] = swap;
			i = 0;
		}
	}
}
