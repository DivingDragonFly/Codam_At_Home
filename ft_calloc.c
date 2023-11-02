/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:23:09 by msinke            #+#    #+#             */
/*   Updated: 2023/10/28 22:47:22 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	total_size;
	void	*ptr;

	if (!num_elements || !element_size)
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
