# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 11:35:04 by ssicard           #+#    #+#              #
#    Updated: 2017/03/04 16:31:51 by ssicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a ft_printf/libftprintf.a


SRC =   main.c \
		malloc.c \
		print.c

OBJ = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)

	make -C libft
	@echo "Compiling $(NAME)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c $@
	@$(CC) $(FLAGS) -c $<
	@echo "Compilation of $<"

clean:
	@make -C libft clean
	@echo "Deleting objects of the library"
	@rm -rf $(OBJ)
	@echo "Objecting deleting....."

fclean: clean
	@make -C libft fclean
	@echo "Deleting the lib"
	@rm -rf $(NAME)
	@echo "delete of $(NAME)"

re: fclean all
