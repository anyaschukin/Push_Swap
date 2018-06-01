/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:09:54 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/05 15:47:01 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a unicode string as argument,
** reads through the unicode character by character (calling ft_unicode),
** and stores/returns a unicode/wchar_t string
*/

char	*ft_strunicode(wchar_t *s)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*del;

	if (!s || !(str = ft_strnew(0)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		del = str;
		tmp = ft_unicode(s[i]);
		str = ft_strjoin_free(str, tmp, 3);
		i++;
	}
	return (str);
}
