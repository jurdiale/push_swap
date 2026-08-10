# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/10 22:12:22 by pabfajar          #+#    #+#              #
#    Updated: 2026/08/10 22:48:01 by pabfajar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap.a
NAME2 = checker.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_SHARED = operations/swap.c operations/push.c\
 operations/rotate.c operations/reverse_rotate.c\
 parse/stack_utils_1.c parse/stack_utils_2.c stack/stack_ops_1.c\
 stack/stack_ops_2.c parse/validate.c parse/normalize.c\
 parse/error.c

SRCS_PS = main.c parse/parse_flags.c bench.c\
algorithms/simple.c algorithms/medium.c algorithms/complex.c\
algorithms/lineal.c algorithms/adaptative.c push_swap_utils.c\
push_swap_utils_2.c

SRCS_CH = bonus/checker

OBJS_SHARED = $(SRCS_SHARED:.c=.o)
OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_SHARED) $(OBJS_PS)
	$(CC) $(CFLAGS) $(OBJS_SHARED) $(OBJS_PS) -o $(NAME1)

$(NAME2): $(OBJS_SHARED) $(OBJS_CH)
	$(CC) $(CFLAGS) $(OBJS_SHARED) $(OBJS_CH) -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	# $< = archivo fuente (.c) $@ = archivo destino (.o)

clean:
	rm -f $(OBJS_SHARED) $(OBJS_PS) $(OBJS_CH)

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re