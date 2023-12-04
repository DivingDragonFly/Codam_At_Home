# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msinke <msinke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:10:36 by msinke            #+#    #+#              #
#    Updated: 2023/12/04 15:47:41 by msinke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

DEPENDENCIES = ft_printf.h

SRCS = src/ft_putnbr.c \
	   src/ft_putstr.c \
	   src/print_hex.c \
	   ft_printf.c \
	   src/ft_strlen.c \
	   src/ft_char.c \
	   src/ft_isascii.c \
	   src/ft_ptr.c \
	   src/ft_string.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(DEPENDENCIES)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
