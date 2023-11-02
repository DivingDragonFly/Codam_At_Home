/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:50:26 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:41:19 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-0xDEAD);
	while (n-- && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] \
				- (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_strncmp("t\200", "\0", 6));

// 	return (0);
// }