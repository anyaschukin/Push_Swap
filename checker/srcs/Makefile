# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 11:26:59 by aschukin          #+#    #+#              #
#    Updated: 2018/05/09 11:27:02 by aschukin         ###   ########.fr        #
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
