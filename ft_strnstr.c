/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:34:48 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 16:10:21 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	little_len = ft_strlen(little);
	size_t			i;

	i = 0;
	if (!little || !big)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (i < len)
	{
		if (ft_strncmp((big + i), little, little_len) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	big[] = "BigString";
// 	const char	little[] = "";
// 	size_t		len;

// 	len = 7;
// 	printf("%s\n", (char *)strnstr(big, little, len));
// 	printf("%s\n", (char *)ft_strnstr(big, little, len));
// 	return (0);
// }
