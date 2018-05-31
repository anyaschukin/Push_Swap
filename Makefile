# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 11:26:59 by aschukin          #+#    #+#              #
#    Updated: 2018/05/10 10:31:21 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     TEMPORARY MAKEFILE        #

all: remove checker push_swap

checker:
	make -C libftprintf
	cp libftprintf/libftprintf.a .
	gcc -Wall -Werror -Wextra srcs/checker/*.c srcs/shared/*.c libftprintf.a -o checker -I includes -I libftprintf/srcs/libft/includes/ -I libftprintf/includes


push_swap: 
	make -C libftprintf
	cp libftprintf/libftprintf.a .
	gcc -Wall -Werror -Wextra srcs/push_swap/*.c srcs/shared/*.c libftprintf.a -o push_swap -I includes -I libftprintf/srcs/libft/includes/ -I libftprintf/includes

remove:
	rm -rf libftprintf.a checker push_swap

fclean:
	make -C libftprintf fclean
	rm -rf libftprintf.a checker push_swap

re:
	fclean all
