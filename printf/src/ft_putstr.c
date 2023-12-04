/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:54:27 by msinke            #+#    #+#             */
/*   Updated: 2023/12/02 23:10:25 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s) * sizeof(char));
	return (ft_strlen(s));
}

// int main(void)
// {
// 	char *s2;

// 	s2 = "Hallo";
// 	printf("original function");
// 	printf("\n%s", "");
// 	printf("\n %s", "");
// 	printf("\n %s %s %s %s %s", " - ", "", "4", "", s2);
// 	// printf(" NULL %s NULL ", NULL);
// 	return (0);
// }
