/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:34:28 by msinke            #+#    #+#             */
/*   Updated: 2023/12/04 15:47:39 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

size_t	ft_strlen(const char *a);
int		ft_char(const int c);
int		ft_string(const char *buf);
size_t	ft_putstr(char *s);
int		ft_isascii(int n);
int		recursive_putnbr(int n);
int		ft_putnbr(int n);
size_t	ft_putstr(char *s);
int		ft_ptr(void *value);
size_t	print_hex(uintptr_t value, bool upper);
size_t	print_adress(void	*value);
size_t	ft_hexlow(int x);
size_t	ft_hexup(int X);
int		ft_printf(const char *str, ...);

