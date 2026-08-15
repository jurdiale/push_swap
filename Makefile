# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/10 22:12:22 by pabfajar          #+#    #+#              #
#    Updated: 2026/08/13 19:36:06 by pabfajar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -I . -I bonus/

SRCS_SHARED = operations/swap.c operations/push.c\
 operations/rotate.c operations/reverse_rotate.c\
 parse/stack_utils_1.c parse/stack_utils_2.c stack/stack_ops_1.c\
 stack/stack_ops_2.c stack/stack_ops_3.c parse/validate.c\
 parse/normalize.c parse/error.c

SRCS_PS = push_swap.c parse/parse_flags.c bench.c\
algorithms/simple.c algorithms/medium.c algorithms/complex.c\
algorithms/adaptive.c push_swap_utils_1.c\
push_swap_utils_2.c push_swap_utils_3.c

BONUS_SRCS = bonus/checker.c bonus/checker_utils.c push_swap_utils_1.c\
bonus/get_next_line.c bonus/get_next_line_utils.c push_swap_utils_2.c\
push_swap_utils_3.c

OBJS_SHARED = $(SRCS_SHARED:.c=.o)
OBJS_PS = $(SRCS_PS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME1)

$(NAME1): $(OBJS_SHARED) $(OBJS_PS)
	$(CC) $(CFLAGS) $(OBJS_SHARED) $(OBJS_PS) -o $(NAME1)

bonus: $(NAME2)

$(NAME2): $(OBJS_SHARED) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS_SHARED) $(BONUS_OBJS) -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	# $< = archivo fuente (.c) $@ = archivo destino (.o)

clean:
	rm -f $(OBJS_SHARED) $(OBJS_PS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re