# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 10:27:55 by aschukin          #+#    #+#              #
#    Updated: 2018/06/02 00:14:08 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = sources
SRC_NAME = ft_printf.c \
			ft_init_struct.c ft_check_flags.c ft_check_length.c \
			ft_check_precision.c ft_check_width.c ft_check_errors.c \
			ft_printf_conversion.c \
			flag_c.c flag_d.c flag_p.c flag_o.c flag_s.c flag_u.c flag_x.c \
			flag_percent.c combine.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = objects
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH = includes
INC_NAME = ft_printf.h
INCLUDES = $(addprefix $(INC_PATH)/,$(INC_NAME))

CFLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

libftcomp:
	@make all -C libft/

$(NAME): libftcomp $(OBJ) $(LIB)
	@libtool -static -o $(NAME) $(LIB) $(OBJ)

$(OBJ): $(OBJ_PATH) $(SRC) $(INC_PATH)
	@gcc $(CFLAGS) -c $(SRC)
	@mv $(OBJ_NAME) $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(INC_PATH):
	@mkdir $(INC_PATH) 2> /dev/null || true
	@mv $(INC_NAME) $(INC_PATH)

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@rm -f $(OBJ_NAME)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
