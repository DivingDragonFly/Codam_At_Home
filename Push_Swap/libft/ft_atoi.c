/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:56:49 by msinke            #+#    #+#             */
/*   Updated: 2024/04/20 15:39:47 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t		num;
	size_t		i;
	int			min;
	const char	*whitespace = " \f\n\r\t\v";

	i = 0;
	num = 0;
	min = 1;
	while (ft_strchr(whitespace, nptr[i]) != NULL)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			min *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num = num + (nptr[i++] - '0');
	}
	return (num * min);
}
