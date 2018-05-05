/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:27 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/03 18:28:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_trailing(char const *s)
{
	int		j;

	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	return (j);
}

static int	ft_calc_leading(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_calc_leading(s);
	j = ft_calc_trailing(s);
	k = 0;
	if (i == ft_strlen(s))
	{
		if (!(str = ft_strnew(0)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strnew((j + 1) - i)))
			return (NULL);
		while (i <= j)
			str[k++] = s[i++];
	}
	return (str);
}
