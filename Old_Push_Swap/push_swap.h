/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:55:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/05 21:05:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdlib.h>
#include <limits.h>


typedef struct	s_stack
{
	int				data;
	struct s_clist	*next;
	struct s_clist	*prev;
}				t_stack;

typedef struct	s_frame
{
	struct s_stack *a;
	struct s_stack *b;
	int				argc;
	char			**argv;
}					t_frame;

typedef void		(*t_table)(t_frame *frame);

/*
** Create, add to, and remove from Circular Doubly-Linked List
*/

void	checker(t_frame *frame);
void	push_swap_free(t_frame *frame);
void	push_swap_error(t_frame *frame);

t_stack*	create_clist(t_stack *tmp, int data);
void		add_before(t_stack *element, int data);
void		add_after(t_stack *element, int data);
void		add_to_top(t_stack *head, int data);
void		add_to_tail(t_stack *head, int data);

void		remove_element(t_stack *element);
void		remove_first_element(t_stack *head);
void		remove_last_element(t_stack *head);


t_stack		*parser(char *str);
int			check_duplicate(t_stack *head);

void		swap(t_stack **head);

#endif
