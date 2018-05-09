/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:34:49 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/23 10:43:30 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memchr() function scans the intial n bytes of memory pointed to by s
** for the first instance of c. Returns a pointer to the located character,
** or a null pointer if the character does not occur in the object.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char*)s;
	while (i < n)
	{
		if (*p != (char)c)
		{
			p++;
			i++;
		}
		else
		{
			return (p);
		}
	}
	return (0);
}
