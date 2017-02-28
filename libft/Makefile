# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:39:09 by ssicard           #+#    #+#              #
#    Updated: 2016/03/27 13:26:22 by ssicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Defining the compiler
CC=gcc

NAME = libft.a

SRC = ft_bzero.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strncpy.c \
	  ft_putnbr.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strlcat.c \
	  ft_atoi.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strncat.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_memalloc.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_putendl.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strsplit.c\
	  ft_cslen.c\
	  ft_getchar_len2.c\
	  ft_getnbr.c\
	  ft_getwchar.c\
	  ft_ibull.c\
	  ft_putnwstr.c\
	  ft_putwchar_fd.c\
	  ft_strjoina.c\
	  ft_strjoinb.c\
	  ft_wcslen.c\
	  ft_lstnew.c\
	  get_next_line.c\
	  ft_list_push_back.c\
	  ft_lstadd.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_push_back.c\
	  ft_list_end.c\
	  ft_sort_list.c

OBJ = $(patsubst %.c,%.o,$(SRC))

OBJ2 = $(SRC:.c=.o)

FLAGS =

HEADERS = includes

all : $(NAME)
	@echo all: make complete

$(NAME) : $(OBJ2)
	@$(CC) $(FLAGS) -c $(SRC) -I $(HEADERS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o:%.c
	@$(CC) -c -o $@ $(FLAGS) $^

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

#Naming my phony targets
.PHONY: all clean fclean re
