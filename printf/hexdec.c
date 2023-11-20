/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:06 by msinke            #+#    #+#             */
/*   Updated: 2023/11/20 20:27:48 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_hex(uintptr_t value, bool upper)
{
	char		c;
	uintptr_t	num;

	num = value;
	if (num >= 16)
	{
		print_hex((num / 16), upper);
	}

	if ((num % 16) < 10)
	{
		c = (num % 16) + '0';
	}
	else if ((num % 16) >= 10)
	{
		if (upper)
			c = (((num % 16) - 10) + 'A');
		else
			c = (((num % 16) - 10) + 'a');
	}
	write(1, &c, 1);
}
