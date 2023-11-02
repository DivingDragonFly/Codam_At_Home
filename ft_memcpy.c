/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:02:59 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:20:50 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
