/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:08 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/03 13:48:22 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = -1;
	s = str;
	ft_strlowcase(str);
	while (s[i] != '\0')
	{
		if (j == -1 || ft_isalnum(s[j]) == 0)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}
		i++;
		j++;
	}
	return (str);
}
