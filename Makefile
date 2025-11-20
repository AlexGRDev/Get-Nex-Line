# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.co> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 21:25:00 by agarcia2          #+#    #+#              #
#    Updated: 2025/11/20 21:25:00 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a

SRCS		= get_next_line.c \
		  get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c get_next_line.h get_next_line_utils.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

