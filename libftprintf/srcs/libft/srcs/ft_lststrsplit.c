/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:36:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/14 11:43:37 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		**ft_lstdelim(t_list **head, char *s, char c, int j)
{
	t_list	*lst;
	int		i;

	while ((i = 0) == 0 && (s[i] != '\0' || s[i - 1] != '\0'))
	{
		j = (!(s[i] == c)) ? (j += 1) : (j += 0);
		i = (s[i + 1] == '\0') ? (i += 1) : (i += 0);
		if ((j = 0) == 0 && (s[i] == c || s[i] == '\0'))
		{
			if (i == 0)
			{
				if (!(lst = ft_lstnew(ft_strndup(s + (i - j), j), j + 1)))
					return (0);
				head = &lst;
			}
			else
			{
				if (!(lst->next = ft_lstnew(ft_strndup(s + (i - j), j), j + 1)))
					return (0);
				lst = lst->next;
			}
		}
		i++;
	}
	return (0);
}

t_list			**ft_lststrsplit(char const *s, char c)
{
	char	*trimmed;
	char	*removed;
	t_list	**head;
	int		j;

	j = 0;
	head = NULL;
	trimmed = ft_strtrimselect(s, c);
	removed = ft_removeselect(trimmed, c);
	ft_lstdelim(head, removed, c, j);
	return (head);
}
