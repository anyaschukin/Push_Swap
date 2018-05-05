/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:46 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/03 15:56:17 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (ft_strlen(dst) < dstsize) ? ft_strlen(dst) : dstsize;
	len += ft_strlen(src);
	if (dstsize)
	{
		while (*dst)
		{
			dst++;
			i++;
		}
		while (*src && i < (dstsize - 1))
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (len);
}
