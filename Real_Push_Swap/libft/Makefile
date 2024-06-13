# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msinke <msinke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 14:40:23 by msinke            #+#    #+#              #
#    Updated: 2024/06/13 18:12:05 by msinke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

DEPENDENCIES = libft.h

SRC = ft_atoi.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_split.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(DEPENDENCIES)
		ar rcs $(NAME) $(OBJ)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: clean all

.PHONY: all clean re


	
