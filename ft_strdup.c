/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:13:31 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 15:50:47 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const size_t	size = ft_strlen(s);
	char			*duplicate;

	if (!s)
		return (NULL);
	duplicate = (char *)ft_calloc((size + 1), sizeof(char));
	ft_memcpy(duplicate, s, size - 1);
	return (duplicate);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strdup(("coucou") + 1));
// 	printf("original %s\n", strdup(("coucou") + 1));
// 	return (0);
// }