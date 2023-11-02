/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:49:36 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:39:56 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	src_len = ft_strlen(src);

	if (size == 0)
		return (src_len);
	ft_memcpy(dst, src, size - 2);
	dst[size - 1] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char src[] = "coucou";
// 	char dst[10];
// 	// char dst1[10];

// 	// printf("ft %zu\n", ft_strlcpy(dst, src, -1));
// 	// printf("ft %s\n", dst);
// 	printf("%zu\n", strlcpy(dst, src, -1));
// 	printf("%s\n", dst);

// 	return (0);
// }
