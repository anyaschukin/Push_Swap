/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:27:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/31 16:15:09 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Writes n zeroed bytes into the string s
** If n is zero, bzero() does nothing
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = (char*)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
