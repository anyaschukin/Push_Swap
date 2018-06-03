# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 21:46:20 by aschukin          #+#    #+#              #
#    Updated: 2018/06/01 21:46:22 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP =		push_swap
CHECKER =		checker
NAME =			$(PUSH_SWAP) $(CHECKER)
LIBFT_A =		libftprintf.a

COMP =			gcc -Wall -Werror -Wextra -I includes -I libft/includes -I libft/libft -c -o

OBJ_DIR =		obj/
S_SRC_DIR =		srcs/shared/
P_SRC_DIR =		srcs/push_swap/
C_SRC_DIR =		srcs/checker/
LIBFT =			libft/

S_SRC =			create_frame.c \
				display_stacks.c \
				do_pa.c \
				do_pb.c \
				do_ra.c \
				do_rb.c \
				do_rr.c \
				do_rra.c \
				do_rrb.c \
				do_rrr.c \
				do_sa.c \
				do_sb.c \
				do_ss.c \
				fill_stack_a.c \
				push_swap_error.c \
				push_swap_free.c \
				stack_add_end.c \
				stack_add_top.c \
				stack_del_top.c

P_SRC =			find_biggest_smallest.c \
				find_median.c \
				find_moves.c \
				find_stack_len.c \
				insertion_solve_half.c \
				insertion_solve_quarters.c \
				push_median.c \
				push_quarters.c \
				push_swap.c \
				reset_moves.c \
				solve_5_or_less.c \
				solver.c \
				sorted.c

C_SRC =			checker.c \
				do_launch.c \
				sort_test.c

S_OBJ =			$(S_SRC:%.c=%.o)
P_OBJ =			$(P_SRC:%.c=%.o)
C_OBJ =			$(C_SRC:%.c=%.o)
OBJ =			$(S_OBJ) $(P_OBJ) $(C_OBJ)

S_SRC_PATH =   	$(S_SRC:%=$(S_SRC_DIR)%)
P_SRC_PATH =   	$(P_SRC:%=$(P_SRC_DIR)%)
C_SRC_PATH =   	$(C_SRC:%=$(C_SRC_DIR)%)
SRC_PATH =		$(S_SRC_PATH) $(P_SRC_PATH) $(C_SRC_PATH)

S_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(S_OBJ))
P_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(P_OBJ))
C_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(C_OBJ))
OBJ_PATH =		$(S_OBJ_PATH) $(P_OBJ_PATH) $(C_OBJ_PATH)

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m PUSH_SWAP AND CHECKER COMPLETE \033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(S_OBJ_PATH) $(P_OBJ_PATH) *.a -o push_swap \
					-I includes -I libft/includes
				@gcc $(S_OBJ_PATH) $(C_OBJ_PATH) *.a -o checker \
					-I includes -I libft/includes

$(S_OBJ_PATH):	$(S_SRC_PATH)
				@$(MAKE) $(S_OBJ)

$(P_OBJ_PATH):	$(P_SRC_PATH)
				@$(MAKE) $(P_OBJ)

$(C_OBJ_PATH):	$(C_SRC_PATH)
				@$(MAKE) $(C_OBJ)

$(S_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(S_SRC_DIR)$(@:%.o=%.c)
$(C_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(C_SRC_DIR)$(@:%.o=%.c)
$(P_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(P_SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo "\\n\033[32;1m Cleaned libft object files \033[0m"

fclean:			clean
				@/bin/rm -f $(PUSH_SWAP) $(CHECKER) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo "\\n\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: 			fclean all

.PHONY:			all clean flcean re color
