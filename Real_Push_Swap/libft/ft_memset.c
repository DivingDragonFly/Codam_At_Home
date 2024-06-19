/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:27 by msinke            #+#    #+#             */
/*   Updated: 2024/04/20 15:40:03 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
