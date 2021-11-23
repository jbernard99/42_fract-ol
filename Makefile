# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 15:28:55 by jbernard          #+#    #+#              #
#    Updated: 2021/11/23 14:29:15 by jbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal.out
HEADER = fractal.h
SRC = main.c \
	fractal.c \
	sets.c \
	events_managers.c \
	mouse_events.c \
	key_events.c \
	mlx_tools.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : fclean $(SRC)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all