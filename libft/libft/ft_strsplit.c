/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:41:17 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/28 14:58:30 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings
** (all ending with ’\0’, including the array itself) obtained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
**
** len = total # of words we expect and allocate for
** count = the # of words we've gone through
** i = character index counter
**
** line 68: Once we know the length of the current word,
** use its length to get the substring of our input string.
*/

#include "libft.h"

static char	**ft_protect(char const *s, char c)
{
	char	**strings;
	int		len;

	if (!s || !c)
		return (NULL);
	len = ft_delim_count(s, c);
	if (!(strings = (char**)malloc((len + 1) * sizeof(char*))))
		return (NULL);
	return (strings);
}

static char	**ft_allthework(char const *s, char **strings, int len, char c)
{
	int i;
	int count;
	int wordlen;

	count = 0;
	i = 0;
	while (count < len)
	{
		wordlen = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			wordlen++;
			i++;
		}
		strings[count++] = ft_strsub(&s[i - wordlen], 0, wordlen);
	}
	strings[count] = 0;
	return (strings);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		len;

	strings = ft_protect(s, c);
	if (strings == NULL)
		return (NULL);
	len = ft_delim_count(s, c);
	strings = ft_allthework(s, strings, len, c);
	return (strings);
}
