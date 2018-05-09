/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:19:02 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/27 19:03:05 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or
** at the end of the string. The following characters will be considered
** as whitespaces: ’ ’, ’\n’ and ’\t’. If s has no whitespaces
** at the beginning or at the end, the function returns
** a copy of s. If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*fresh;
	size_t		sta;
	size_t		end;
	size_t		len;

	if (!s)
		return (0);
	sta = 0;
	end = ft_strlen(s) - 1;
	while (s[sta] && (s[sta] == ' ' || s[sta] == '\n' || s[sta] == '\t'))
		sta++;
	while (sta < end && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	len = end - sta + 1;
	fresh = ft_strsub(s, sta, len);
	return (fresh);
}
