/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:24:20 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:10:07 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t			num;
	size_t			i;
	int				min;

	i = 0;
	num = 0;
	min = 1;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n' \
	|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			min *= -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num = num + (nptr[i++] - '0');
	}
	return (num * min);
}
// int	main(void)
// {
// 	printf("%d\n", ft_atoi("+47+5"));
// 	printf("%d\n", atoi("+47+5"));

// 	return (0);
// }