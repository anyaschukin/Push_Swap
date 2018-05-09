/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:47:32 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/07 16:14:48 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct		s_stack
{
	long int		num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_frame
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				argc;
	char			**argv;
}					t_frame;

typedef void			(*t_table)(t_frame *frame);

void		push_swap(t_frame *frame);
void		push_swap_free(t_frame *frame);
void		push_swap_error(t_frame *frame);
void		fill_stack_a(t_frame *frame);
void		stack_del_top(t_frame *frame, char stack_name);
void		stack_add_top(t_frame *frame, char stack_name, int num);
void		stack_add_end(t_frame *frame, char stack_name, int num);
t_frame		*create_frame(t_frame *frame, int argc, char **argv);



#endif
