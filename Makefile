NAME = malloc

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a


SRC =   main.c \
		malloc.c

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
