/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:02:11 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/27 19:01:40 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Appends the NUL-terminated string src to the end of dst.
** Will append at most size- strlen(dst) - 1 bytes, NUL-terminating the result.
** Source and destination strings should not overlap.
** Returns: the intial length of dst + the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lendst;
	unsigned int	lensrc;
	unsigned int	i;

	lendst = 0;
	lensrc = 0;
	i = 0;
	while (dst[lendst])
		lendst++;
	while (src[lensrc])
		lensrc++;
	if (size == 0)
		return (lensrc);
	while (src[i] && ((lendst + i) < (size - 1)))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lensrc + ((lendst < size) ? lendst : size));
}
