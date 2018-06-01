/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:42:03 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 15:58:09 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_strwlen(char *str)
{
	intmax_t	len;
	int			i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((int)str[i] <= 0x7F)
			len++;
		else if ((int)str[i] <= 0x7FF)
			len += 2;
		else if ((int)str[i] <= 0x7FFF)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}
