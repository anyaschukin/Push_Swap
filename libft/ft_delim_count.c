/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delim_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:15:59 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/27 19:18:39 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_delim_count(char const *s, char delimiter)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i] == delimiter)
		i++;
	while (s[i])
	{
		if (s[i] != delimiter)
		{
			count++;
			while (s[i] != delimiter && s[i] != '\0')
				i++;
			continue ;
		}
		i++;
	}
	return (count);
}
