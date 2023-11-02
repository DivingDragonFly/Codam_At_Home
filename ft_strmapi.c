/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:40:31 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:40:21 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	total_len = ft_strlen(s);
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)ft_calloc(total_len + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

