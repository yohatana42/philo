# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 18:15:10 by yoshiko           #+#    #+#              #
#    Updated: 2025/04/16 22:16:18 by yoshiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
SRCS	=\
	srcs/main.c\
	srcs/validation_args.c\
	srcs/ft_atoi.c\
	srcs/ft_strlen.c\
	srcs/create_struct_table.c\
	srcs/ft_calloc.c
HEADERS	=\
	includes/philo.h
OBJS	= $(SRCS:.c=.o)

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I includes/

.DEFAULT:	all

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re