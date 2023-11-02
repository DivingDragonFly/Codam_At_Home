/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:43:01 by msinke            #+#    #+#             */
/*   Updated: 2023/10/28 22:10:04 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ft_substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	ft_substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (ft_substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		ft_substr[i++] = s[start++];
	return ((char *)ft_substr);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("hallobitchdfdf", 3, 7));
// 	return (0);
// }