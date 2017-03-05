# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 11:35:04 by ssicard           #+#    #+#              #
#    Updated: 2017/03/05 12:21:25 by ssicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a ft_printf/libftprintf.a

SRC =   malloc.c \
		print.c \
		free_realloc.c \
		free_realloc2.c

OBJ = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -shared -o $(NAME) $(OBJ) $(LIB)
	@echo "Compiling $(NAME)"
	@ln -s $(NAME) libft_malloc.so

%.o: %.c $@
	@$(CC) -c $(FLAGS) -I./includes/ -I./libft/includes $<
	@echo "Compilation of $<"

clean:
	@make -C libft clean
	@echo "Deleting objects of the library"
	@rm -f $(OBJ)
	@rm -f libft_malloc.so
	@echo "Objecting deleting....."

fclean: clean
	@make -C libft fclean
	@rm -f libft_malloc.so
	@echo "Deleting the lib"
	@rm -f $(NAME)
	@echo "delete of $(NAME)"

re: fclean all
