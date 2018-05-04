/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:40:53 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/28 10:46:52 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copies len bytes of value of c (converted to an unsigned char)
** to the string b.
** Returns: function returns its first argument
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	size_t	i;

	p = (char*)b;
	i = 0;
	while (i < len)
	{
		p[i] = (char)c;
		i++;
	}
	return (b);
}
