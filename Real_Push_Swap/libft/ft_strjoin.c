/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:54 by msinke            #+#    #+#             */
/*   Updated: 2024/04/20 15:40:07 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
