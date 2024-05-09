# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 10:10:05 by sganiev           #+#    #+#              #
#    Updated: 2024/05/08 14:50:32 by sganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC1 = get_next_line.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c \

OBJ1 = $(SRC1:.c=.o)

SRC2 = ft_printf.c ft_putchar_modified.c ft_putstr_modified.c print_character.c \
print_decimal.c print_hexadec.c print_other.c print_percent.c print_pointer.c \
print_string.c print_unsig_decimal.c \

OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ1) $(OBJ2)
	ar rc $(NAME) $(OBJ1) $(OBJ2)
	ranlib $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re