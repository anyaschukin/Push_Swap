/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:33:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/05 23:29:55 by dhojt            ###   ########.fr       */
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

void				checker(t_frame *frame);
void				push_swap_exit(t_frame *frame);
void				fill_stack_a(t_frame *frame);
void				stack_del_top(t_frame *frame, char stack_name);
void				stack_add_top(t_frame *frame, char stack_name, int num);
void				stack_add_end(t_frame *frame, char stack_name, int num);
t_frame				*create_frame(t_frame *frame, int argc, char **argv);
#endif
