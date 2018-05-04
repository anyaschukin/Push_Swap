/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:59:25 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 16:01:46 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates with malloc and returns a 'fresh' string ending with '\0'.
** Each character of the string is initialized at '\0'
** If the allocation fails, the funciton returns NULL.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
