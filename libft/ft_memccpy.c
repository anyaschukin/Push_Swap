/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:23:40 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/27 19:00:22 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Memccpy copies bytes from memory area s2 into s1,
** stopping after the first occurrence of c has been copied,
** or after n bytes have been copied, whichever comes first.
** Returns: a pointer to the first byte after c in s1 or,
** if c was not found in the first n bytes of s2, it returns a null pointer.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*newdst;
	unsigned char	*newsrc;
	unsigned char	a;
	unsigned long	i;

	newdst = (unsigned char*)dst;
	newsrc = (unsigned char*)src;
	a = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		*newdst = *newsrc;
		if (*newsrc == a)
		{
			newdst++;
			return (newdst);
		}
		newdst++;
		newsrc++;
		i++;
	}
	return (NULL);
}
