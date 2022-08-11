# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 12:57:04 by hyunkyle          #+#    #+#              #
#    Updated: 2022/08/11 20:22:53 by hyunkyle         ###   ########.fr        #
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

BONUS_SRCS = 		checker_bonus.c \
					my_deque.c \
					my_stack.c \
					my_stack_utils1_bonus.c \
					my_stack_utils2_bonus.c \
					my_stack_utils3_bonus.c \
					ps_utils.c \
					ps_utils6.c \

BONUS_OBJS= $(BONUS_SRCS:.c=.o)					
					
NAME = push_swap

BONUS_NAME = checker

FLAGS = -Wall -Wextra -Werror

CC = cc

all	: $(NAME)

$(NAME)	: $(OBJS)
	make -C ./libft
	$(CC) $(FLAGS) -g -o $(NAME) $(OBJS) -Llibft -lft

bonus : 
	make all
	make $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	make -C ./get_next_line
	make -C ./libft
	$(CC) $(FLAGS) -g -o $(BONUS_NAME) $(BONUS_OBJS) -Llibft -lft ./get_next_line/libgnl.a

.c.o :
	$(CC) -o $@ -c $<
	
clean	:
		make -C ./libft clean
		make -C ./get_next_line clean
		rm -f $(OBJS)
		rm -f $(BONUS_OBJS)

fclean	:	clean
		make -C ./libft fclean
		make -C ./get_next_line fclean
		rm -f $(NAME)
		rm -f $(BONUS_NAME)

re	:
	make fclean
	make all

.PHONY	:	all clean fclean re bonus