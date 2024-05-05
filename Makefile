# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 13:42:57 by sganiev           #+#    #+#              #
#    Updated: 2024/05/05 14:03:17 by sganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_program
SRC = test_1.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -L/Users/sganiev/Study/So_long -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C ./mlx -s
	@mv ./mlx/libmlx.dylib ./
	$(CC) $(CFLAGS) $(SRC) $(MLX) -o $(NAME)

clean:
	make -C ./mlx -s clean

fclean: clean
	@rm -rf libmlx.dylib

re: fclean all
	make -C ./mlx re

.PHONY: all, clean, fclean, re