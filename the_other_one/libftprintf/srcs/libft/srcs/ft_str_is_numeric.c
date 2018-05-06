/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:03 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/03 13:46:42 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_numeric(char *str)
{
	int fail;

	fail = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			fail = 1;
		str++;
	}
	return ((fail) ? 0 : 1);
}
