# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 02:39:16 by dhojt             #+#    #+#              #
#    Updated: 2018/05/05 17:39:42 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     TEMPORARY MAKEFILE        #

all:
	make -C ../../libftprintf
	cp ../../libftprintf/libftprintf.a .
	gcc *.c  libftprintf.a -I ../includes -I ../../libftprintf/srcs/libft/includes

fclean:
	rm libftprintf.a a.out
	make -C ../../libftprintf fclean
