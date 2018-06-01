/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:24:46 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/08 19:06:19 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Mallocs a new string s1 + s2 and frees the the strings passed as parameters
*/

char		*ft_strjoin_free(char *s1, char *s2, size_t to_free)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(str = ft_strnew(s1_size + s2_size)))
		return (NULL);
	ft_memmove(str, s1, s1_size);
	ft_memmove(str + s1_size, s2, s2_size);
	if (to_free == 1)
		ft_strdel(s1);
	if (to_free == 2)
		ft_strdel(s2);
	if (to_free == 3)
	{
		ft_strdel(s1);
		ft_strdel(s2);
	}
	return (str);
}
