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

NAME		:= so_long

LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a
INCDIRS		:= -I./includes -I$(LIBFT_DIR)

VPATH		:= ./src

SRC			:= so_long.c check_collectible.c check_exit.c		\
			   check_file_name.c check_for_valid_symbols.c		\
			   check_isempty.c check_player.c check_wall.c		\
			   check_width_hight.c free_list.c check_path.c		\
			   flood_fill.c free_arr.c item_search.c			\
			   map_rendering.c events.c put_image.c  cleanup.c	\
			   close_window.c									\

ODIR		:= obj
OBJ			:= $(patsubst %.c,$(ODIR)/%.o,$(SRC))

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror $(INCDIRS)
MLXFLAGS	:= -L./ -lmlx -framework OpenGL -framework AppKit
MLXLIB		:= libmlx.dylib

all: $(ODIR) $(NAME)

$(NAME): $(MLXLIB) $(LIBFT) $(OBJ)
	@echo "linking ..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "executable $(NAME) created successfully!"

$(ODIR):
	@mkdir -p $(ODIR)

$(LIBFT):
	@echo "compiling libft..."
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "library libft created successfully!"

$(ODIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(MLXLIB):
	@echo "building mlx library..."
	@if [ -f ./mlx/minilibx_mms_20200219_beta.tgz ]; then \
		tar -xzvf ./mlx/minilibx_mms_20200219_beta.tgz -C ./mlx; \
		mv ./mlx/minilibx_mms_20200219/* ./mlx; \
		rm -rf ./mlx/minilibx_mms_20200219/; \
		rm -f ./mlx/*.tgz; \
	fi
	@make -C ./mlx > /dev/null 2>&1
	@mv ./mlx/libmlx.dylib ./
	@echo "mlx library created successfully!"

clean:
	@echo "cleaning up temporary files..."
	@make -C ./mlx -s clean
	@make -C ./libft -s clean
	@rm -f $(OBJ)
	@echo "temporary files removed successfully!"

fclean: clean
	@echo "removing generated files..."
	@rm -rf libmlx.dylib
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@rm -rf $(ODIR)
	@echo "all generated files removed successfully!"

re: fclean all

.PHONY: all clean fclean re mlx_lib
