/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:08:15 by msinke            #+#    #+#             */
/*   Updated: 2024/04/20 15:40:00 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
