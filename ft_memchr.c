/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:50:38 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:16:06 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	chr = c;
	const unsigned char	*str = \
	(const unsigned char *)s;
	size_t				i;

	if (!s)
		return (NULL);
	i = 0;
	while (n--)
		if (str[i++] == chr)
			return ((void *)s + --i);
	return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "String";
// 	int			c;
// 	size_t		n;

// 	n = 5;
// 	c = 'i';
// 	printf("%s", (char *)ft_memchr(s, c, n));
// 	return (0);
// }
