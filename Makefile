# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 12:57:04 by hyunkyle          #+#    #+#              #
#    Updated: 2022/08/11 10:41:36 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= my_deque.c \
					my_stack_utils1.c \
					my_stack_utils2.c \
					my_stack_utils3.c \
					my_stack.c \
					ps_utils.c \
					ps_utils1.c \
					ps_utils2.c \
					ps_utils3.c \
					ps_utils4.c \
					ps_utils5.c \
					ps_utils6.c \
					push_swap.c


OBJS = $(SRCS:.c=.o)

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

CC = cc

all	: $(NAME)

$(NAME)	: $(OBJS)
	make -C ./libft
	$(CC) $(FLAGS) -g -o $(NAME) $(OBJS) -Llibft -lft

bonus : all

clean	:
		make -C ./libft clean
		rm -f $(OBJS)

fclean	:	clean
		make -C ./libft fclean
		rm -f $(NAME)

re	:
	make fclean
	make all

.PHONY	:	all clean fclean re