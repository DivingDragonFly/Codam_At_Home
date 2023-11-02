/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:36:33 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 15:10:02 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sauce;

	if (src == dest || n == 0
		|| dest == NULL || src == NULL)
		return (dest);
	dst = (unsigned char *)dest;
	sauce = (const unsigned char *)src;
	if (dst > sauce)
	{
		i = n - 1;
		while (i > 0)
		{
			dst[i] = sauce[i];
			i--;
		}
		dst[i] = sauce[i];
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

// int	main(void)
// {
// 	char dest[] = { 0,  0,  0,  0,  0,  0, 0};
// 	char src[] = {65, 66, 67, 68, 69, 0, 45};

// 	printf("ft_mem\n %s\n", (char *)ft_memmove(dest, src, 7));
// 	// printf("ft_mem %s\n", (char *)ft_memmove(dest, dest - 2, 5));
// 	printf("mem\n %s\n", (char *)memmove(dest, src, 7));
// 	// printf("mem %s\n", (char *)memmove(dest, dest - 2, 5));

// 	return (0);
// }