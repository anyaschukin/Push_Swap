/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_clist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:35:17 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/05 17:35:22 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_element(t_clist *element)
{
	element->prev->next = element->next;
	element->next->prev = element->prev;
	free(element);
}

void	remove_first_element(t_clist *head)
{
	if (head->next != head)
		remove_element(head->next);
}

void	remove_last_element(t_clist *head)
{
	if (head->prev != head)
		remove_element (head->prev);
}
