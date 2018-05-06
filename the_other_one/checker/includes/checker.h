/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:33:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 05:11:22 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

//OFF
# define DEBUG(f_, ...); printf("");

//ON
//# define DEBUG(f_, ...); printf((f_), __VA_ARGS__);

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

typedef void		(*t_table)(t_frame *frame);

void				checker(t_frame *frame);
void				push_swap_free(t_frame *frame);
void				push_swap_error(t_frame *frame);
void				fill_stack_a(t_frame *frame);
void				stack_del_top(t_frame *frame, char stack_name);
void				stack_add_top(t_frame *frame, char stack_name, int num);
void				stack_add_end(t_frame *frame, char stack_name, int num);
t_frame				*create_frame(t_frame *frame, int argc, char **argv);
void				display_stacks(t_frame *frame);
void				do_launch(t_frame *frame);
void				sort_test(t_frame *frame);

void				do_sa(t_frame *frame);
void				do_sb(t_frame *frame);
void				do_ss(t_frame *frame);

void				do_pa(t_frame *frame);
void				do_pb(t_frame *frame);

void				do_ra(t_frame *frame);
void				do_rb(t_frame *frame);
void				do_rr(t_frame *frame);

void				do_rra(t_frame *frame);
void				do_rrb(t_frame *frame);
void				do_rrr(t_frame *frame);
#endif
