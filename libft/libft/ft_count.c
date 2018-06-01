/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:31:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/28 14:11:04 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_count(intmax_t num)
{
	intmax_t	count;
	uintmax_t	neg;

	count = 0;
	if (num <= 0)
	{
		neg = -num;
		count++;
	}
	if (!count)
		while (num > 0)
		{
			num /= 10;
			count++;
		}
	else
		while (neg > 0)
		{
			neg /= 10;
			count++;
		}
	return (count);
}
