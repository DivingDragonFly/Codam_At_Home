/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:43:48 by msinke            #+#    #+#             */
/*   Updated: 2023/12/18 16:30:36 by msinke           ###   ########.fr       */
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

typedef struct s_struct
{
	char	*result;
	char	*buffer;
	char	*temp;
	size_t	index;
	int		buffer_size;
}	t_struct;

void	*ft_calloc(size_t num_elements, size_t element_size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *buf, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *a);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
