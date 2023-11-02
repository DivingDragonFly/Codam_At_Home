/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:14:19 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 15:19:44 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;

	if (!s1 || !s2)
		return (-0xDEAD);
	while (n--)
		if (*str1++ != *str2++)
			return (*--str1 - *--str2);
	return (0);
}

// int	main(void)
// {
// 	const char	s1[] = "Hal";
// 	const char	s2[] = "Hallo";

// 	printf("%d \n", ft_memcmp(s1, s2, 3));
// 	printf("%d \n", memcmp(s1, s2, 3));
// }
