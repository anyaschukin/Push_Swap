# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 02:39:16 by dhojt             #+#    #+#              #
#    Updated: 2018/05/06 07:21:28 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     TEMPORARY MAKEFILE        #

all:
	make -C ../../libftprintf
	cp ../../libftprintf/libftprintf.a .
	gcc *.c  libftprintf.a -I ../includes -I ../../libftprintf/srcs/libft/includes -I ../../libftprintf/includes

fclean:
	make -C ../../libftprintf fclean
	rm libftprintf.a a.out
