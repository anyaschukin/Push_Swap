/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:54:08 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/27 19:02:22 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locates the last occurrence of c in the string pointed to b s.
** The termiating null character is considered to be part of the string...
** Therefore if c is '\0', the function locates the terminating '\0'.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char*)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (p + i);
		i--;
	}
	return (NULL);
}
