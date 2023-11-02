/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:57:41 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:30:21 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len1 = ft_strlen(s1);
	const size_t	len2 = ft_strlen(s2);
	const size_t	size = len1 + len2;
	char			*ft_strjoin;

	if (!s1 || !s2)
		return (NULL);
	ft_strjoin = (char *)ft_calloc(size + 1, sizeof(char));
	if (!ft_strjoin)
		return (NULL);
	ft_memcpy(ft_strjoin, s1, len1);
	ft_memcpy(ft_strjoin + len1, s2, len2);
	return (ft_strjoin);
}
