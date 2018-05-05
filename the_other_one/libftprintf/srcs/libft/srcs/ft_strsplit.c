/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/03 17:53:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char const *s, char c)
{
	int blank;

	blank = 1;
	while (*s)
	{
		if (*s != c)
			blank = 0;
		s++;
	}
	return (blank);
}

static void	ft_newarraydelimstr(char **array, char const *s, char c)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (*s)
	{
		if (*s != c)
			j++;
		if (*s == c || *(s + 1) == '\0')
		{
			array[k] = ft_strnew(j);
			k++;
			j = 0;
		}
		s++;
	}
	array[k] = NULL;
}

static char	**ft_arraydelim(char const *s, char c)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	if (!(array = (char **)malloc((j + 2) * sizeof(char *))))
		return (NULL);
	ft_newarraydelimstr(array, s, c);
	return (array);
}

static void	ft_fillarraydelim(char **array, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[j][k] = s[i];
			k++;
		}
		if (s[i] == c)
		{
			j++;
			k = 0;
		}
		i++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	*str_trim;
	char	*str_condensed;
	char	**array;

	if (!(s && c))
		return (NULL);
	array = NULL;
	if (ft_isblank(s, c) != 0)
	{
		if (!(array = (char **)malloc(1 * sizeof(char *))))
			return (NULL);
		array[0] = NULL;
		return (array);
	}
	if (!(str_trim = ft_strtrimselect(s, c)))
		return (NULL);
	if (!(str_condensed = ft_removeselect(str_trim, c)))
		return (NULL);
	if (!(array = ft_arraydelim(str_condensed, c)))
		return (NULL);
	ft_fillarraydelim(array, str_condensed, c);
	return (array);
}
