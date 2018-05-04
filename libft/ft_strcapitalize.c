/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:10:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/13 17:48:23 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordy(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else
		return (0);
}

static char	ft_lowerupper(int x, char c)
{
	if (x == 0 && ft_wordy(c) == 1)
		c = c - ('a' - 'A');
	else if (x == 1 && ft_wordy(c) == 2)
		c = c + ('a' - 'A');
	return (c);
}

char		*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			j = 1;
			i++;
			continue;
		}
		if (ft_wordy(str[i]) == 1 || ft_wordy(str[i]) == 2)
		{
			str[i] = ft_lowerupper(j, str[i]);
			j = 1;
		}
		else
			j = 0;
		i++;
	}
	return (str);
}
