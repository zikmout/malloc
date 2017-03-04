# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 11:35:04 by ssicard           #+#    #+#              #
#    Updated: 2017/03/04 18:34:22 by ssicard          ###   ########.fr        #
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
	@$(CC) $(FLAGS) -shared -o $(NAME) $(OBJ) $(LIB)
	ln -s $(NAME) libft_malloc.so

%.o: %.c $@
	@$(CC) $(FLAGS) -c $<
	@echo "Compilation of $<"

clean:
	@make -C libft clean
	@echo "Deleting objects of the library"
	@rm -rf $(OBJ)
	@rm -f libft_malloc.so
	@echo "Objecting deleting....."

fclean: clean
	@make -C libft fclean
	@rm -f libft_malloc.so
	@echo "Deleting the lib"
	@rm -rf $(NAME)
	@echo "delete of $(NAME)"

re: fclean all
