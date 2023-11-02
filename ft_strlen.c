/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:00:36 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 15:53:47 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	if (!a)
		return (i);
	while (a[i] != '\0')
		++i;
	return (i);
}

// int	main(void)
// {
// 	char	a[] = "BlaBl334343a";
// 	printf ("%zu", ft_strlen(a));
// 	return (0);
// }
