# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 13:42:57 by sganiev           #+#    #+#              #
#    Updated: 2024/05/08 14:50:06 by sganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game
SRC = so_long.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -L/Users/sganiev/Study/So_long -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

mlx_lib:
	make -C ./mlx -s
	mv ./mlx/libmlx.dylib ./

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): mlx_lib $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make -C ./mlx -s clean
	make -C ./libft -s clean
	rm -f $(OBJ)

fclean: clean
	rm -rf libmlx.dylib
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re