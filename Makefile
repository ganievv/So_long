# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 13:42:57 by sganiev           #+#    #+#              #
#    Updated: 2024/05/28 14:53:07 by sganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c check_collectible.c check_exit.c \
check_file_name.c check_for_valid_symbols.c      \
check_isempty.c check_player.c check_wall.c      \
check_width_hight.c free_list.c check_path.c     \
flood_fill.c free_arr.c item_search.c            \
map_rendering.c events.c put_image.c  cleanup.c  \
close_window.c                                   \

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -L./ -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

mlx_lib:
	@if [ -f ./mlx/minilibx_mms_20200219_beta.tgz ]; then \
		tar -xzvf ./mlx/minilibx_mms_20200219_beta.tgz -C ./mlx; \
		mv ./mlx/minilibx_mms_20200219/* ./mlx; \
		rm -rf ./mlx/minilibx_mms_20200219/; \
		rm -f ./mlx/*.tgz; \
	fi
	make -C ./mlx
	mv ./mlx/libmlx.dylib ./

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): mlx_lib $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make -C ./mlx -s clean
	make -C ./libft -s clean

fclean: clean
	rm -rf libmlx.dylib
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, mlx_lib, $(LIBFT), $(NAME)