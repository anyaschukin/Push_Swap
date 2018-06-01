/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:51:06 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 16:01:13 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Rotates a string or array, of _x_ size by  _x_ amt.
**
** Note how negative rotations are handled:
** rotating an array of size elements amt to the left
** (i.e. with negative values) is the same as rotating it
** size+amt to the right.
*/

static char	*ft_reverse(char *str, intmax_t size)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = size;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char		*ft_strrotate(char *str, intmax_t size, intmax_t amt)
{
	if (amt < 0)
		amt = size + amt;
	ft_reverse(str, size - amt - 1);
	ft_reverse(str + size - amt, amt - 1);
	ft_reverse(str, size - 1);
	return (str);
}
