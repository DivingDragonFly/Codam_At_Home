/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:18:08 by msinke            #+#    #+#             */
/*   Updated: 2024/03/24 17:55:04 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *buffer, char *buffer_readfc)
{
	char	*str;
	size_t	len_buffer;
	size_t	len_buffer_readfc;

	if (!buffer_readfc)
		return (buffer);
	len_buffer = ft_strlen(buffer);
	len_buffer_readfc = ft_strlen(buffer_readfc);
	str = ft_calloc((len_buffer_readfc + len_buffer) + 1, sizeof(char));
	if (!str)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	if (buffer)
		ft_memmove(str, buffer, len_buffer);
	ft_memmove(str + len_buffer, buffer_readfc, len_buffer_readfc);
	free(buffer);
	buffer = NULL;
	return (str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sauce = (const unsigned char *)src;

	dst = (unsigned char *)dest;
	if (dest == NULL || src == NULL)
		return (dest);
	if (dst > sauce && dst < sauce + n)
	{
		i = n;
		while (i-- != 0)
			dst[i] = sauce[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = sauce[i];
			i++;
		}
	}
	return (dest);
}
