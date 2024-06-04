# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msinke <msinke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 14:48:50 by msinke            #+#    #+#              #
#    Updated: 2024/06/04 18:15:42 by msinke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = /usr/local/opt/gcc/bin/gcc-13
# CC = cc
CFLAGS = -Wall -Wextra -Werror

# Path to libft
LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFT_INC = -I libft

#source files
SRC = src/linked_list.c \
			src/main.c \
			src/operations.c \
			src/extra.c \
			src/self_made_sort.c \
			src/quicksort.c \
			src/pivot.c \
			src/quicksort_stackA.c \
			src/Index_List.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I includes $(LIBFT_INC)

.PHONY: all clean fclean re

all : $(NAME)

#rule to link push_swap and libft
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#rule to compile libft
$(LIBFT):
		make -C $(LIBFT_DIR)

#clean object
clean:
		rm -f $(OBJ)
		make -C $(LIBFT_DIR) clean

#remove everything
fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all





#include directory for push_swap headers
# INCLUDES = -I includes $(LIBFT_INC)