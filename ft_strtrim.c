/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:00:23 by msinke            #+#    #+#             */
/*   Updated: 2023/11/02 17:46:19 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ft_strtrim;
	size_t	begin;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return ((char *)s1);
	end = ft_strlen(s1);
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - begin;
	ft_strtrim = (char *)ft_calloc(len + 1, sizeof(char));
	if (ft_strtrim == NULL)
		return (NULL);
	ft_memcpy(ft_strtrim, &s1[begin], len + 1);
	return (ft_strtrim);
}
