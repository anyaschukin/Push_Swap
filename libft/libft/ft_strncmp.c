/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:44:12 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/25 18:37:49 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexiconographically compres the null-terminated strings s1 and s2,
** but only up to n characters.
** Characters that appear after a '\0' are not compared.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int x;

	x = 0;
	while (s1[x] && s1[x] == s2[x] && x < n)
		x++;
	if (x < n)
		return (((unsigned char*)s1)[x] - ((unsigned char*)s2)[x]);
	else
		return (0);
}
