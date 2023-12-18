/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:05 by msinke            #+#    #+#             */
/*   Updated: 2023/12/15 15:52:32 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	total_size;
	void	*ptr;

	if (num_elements == 0 || element_size == 0)
	{
		num_elements = 1;
		element_size = 1;
	}
	if (element_size > (SIZE_MAX / num_elements))
		return (NULL);
	total_size = num_elements * element_size;
	ptr = malloc(total_size);
	ft_bzero(ptr, total_size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *buf, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (!buf)
		return (buf);
	p = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (buf);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sauce;

	if (!dest || !src)
		return (dest);
	i = 0;
	dst = dest;
	sauce = (const unsigned char *)src;
	while (i < n)
	{
		dst[i] = sauce[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	src_len = ft_strlen(src);
	size_t			new_size;

	new_size = 0;
	if (size > 0)
		new_size = size - 1;
	if (new_size > src_len)
		new_size = src_len;
	ft_memcpy(dst, src, new_size);
	if (size > 0)
		dst[new_size] = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	if (!a)
		return (i);
	while (a[i] != '\0')
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len1 = ft_strlen(s1);
	const size_t	len2 = ft_strlen(s2);
	const size_t	size = len1 + len2;
	char			*ft_strjoin;

	if (!s1 || !s2)
		return (NULL);
	ft_strjoin = (char *)ft_calloc(size + 1, sizeof(char));
	if (!ft_strjoin)
		return (NULL);
	ft_memcpy(ft_strjoin, s1, len1);
	ft_memcpy(ft_strjoin + len1, s2, len2);
	return (ft_strjoin);
}