# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 15:08:15 by yohatana          #+#    #+#              #
#    Updated: 2025/05/18 19:38:41 by yohatana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS =\
		src/main.c\
		src/check_valid_argv.c\
		src/ft_atoi.c\
		src/ft_calloc.c\
		src/ft_strlen.c\
		src/init_table.c\
		src/utils.c\
		src/create_threads.c\
		src/clean.c\
		src/routine_monitor.c\
		src/routine_philo.c\
		src/create_struct.c\
		src/free_struct.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

.DEFAULT:	all

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
