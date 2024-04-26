/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:28:23 by msinke            #+#    #+#             */
/*   Updated: 2024/04/20 15:22:53 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

void	*ft_calloc(size_t num_elements, size_t element_size);
int		ft_atoi(const char *nptr);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *buf, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *buffer, char *buffer_readfc);
size_t	ft_strlen(const char *a);

#endif