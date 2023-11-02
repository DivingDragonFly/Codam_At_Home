/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:48:19 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:36:36 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen(src);
	const size_t	totallen = dstlen + srclen;
	size_t			i;

	if (!dst)
		return (srclen);
	if (size < dstlen)
		return (srclen + size);
	if (size == dstlen)
		return (totallen);
	i = 0;
	ft_memcpy(dst + dstlen, src, size - dstlen - 1);
	dst[dstlen + (size - dstlen - 1)] = '\0';
	return (totallen);
}
