/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:18:57 by msinke            #+#    #+#             */
/*   Updated: 2024/03/24 17:55:58 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t		ft_strlen(const char *a);
void		*ft_memset(void *buf, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t num_elements, size_t element_size);
char		*eof(char *buffer);
char		*extract_line(char *buffer);
char		*read_fd(int fd, char *buffer);
char		*get_next_line(int fd);

#endif