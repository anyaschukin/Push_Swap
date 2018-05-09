# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 15:23:21 by aschukin          #+#    #+#              #
#    Updated: 2018/04/17 15:23:25 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   push_swap.a

SRCS    =   libft/ft_putchar.c \
            libft/ft_putnbr.c \
            libft/ft_putstr.c \
            libft/ft_atoi.c \
            libft/ft_isdigit.c \
            srcs/push_swap.c \
			srcs/checker.c \
            srcs/ft_create_clist.c

OBJS    =   $(SRCS:.c=.o)

RM      =   @rm -f

CFLAGS  =   -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

$(NAME) :   $(OBJS)
    @ar rc $(NAME) $(OBJS)
	@echo "\033[32;1m Compilation completed! \033[0m"

all     :   $(NAME)

clean   :
    @make clean -C libft/
	$(RM) $(OBJS)
	@echo "\033[32;1m Cleanup Complete! \033[0m"

fclean  :   clean
    $(RM) $(NAME)
	@echo "\033[32;1m Executables removed! \033[0m"

re      :   fclean all