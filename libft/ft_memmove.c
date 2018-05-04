/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:31:19 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/27 19:01:14 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memmove is just like memcpy, with one important difference:
** instead of copying directly from `src` to `dst`,
** memmove makes a temporary array, copies `src` into
** this temporary array, then copies the temporary array into `dst`.
** This function does the following:
** 1. Allocates a temporary array of size `n`
** 2. Copies `src` into this temporary array
** 3. Copies this temporary array into `dst`
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			((char *)dst)[n] = ((char *)src)[n];
		}
	}
	return (dst);
}
