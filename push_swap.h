/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:55:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/04 17:08:24 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdlib.h>
#include <limits.h>


typedef struct	s_clist
{
	int				data;
	char			c;
	struct s_clist	*next;
	struct s_clist	*prev;
	size_t			nb_elements;
}				t_clist;



/*
** Create, add to, and remove from Circular List
*/

t_clist*	create_clist(t_clist *tmp, int data);
void		add_before(t_clist *element, int data);
void		add_after(t_clist *element, int data);
void		add_to_top(t_clist *head, int data);
void		add_to_tail(t_clist *head, int data);

void		remove_element(t_clist *element);
void		remove_first_element(t_clist *head);
void		remove_last_element(t_clist *head);

t_clist		*parser(char *str);

#endif
