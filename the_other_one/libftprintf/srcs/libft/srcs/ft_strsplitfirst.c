/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpydelim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:33:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/04 16:44:36 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsplitfirst(char *str, char c)
{
	char	*new;

	if (!str)
		return (NULL);
	new = ft_strchr(str, c) + 1;
	*(ft_strchr(str, c)) = '\0';
	return (new);
}
