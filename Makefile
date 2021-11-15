# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 15:28:55 by jbernard          #+#    #+#              #
#    Updated: 2021/11/15 15:35:40 by jbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal.out
HEADER = fractal.h
SRC = main.c fractal.c mandelbrot.c event_handler.c mlx_tools.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(HEADER) $(SRC)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all