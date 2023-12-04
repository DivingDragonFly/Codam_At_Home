/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:06 by msinke            #+#    #+#             */
/*   Updated: 2023/12/02 23:10:27 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_hex(size_t value, bool upper)
{
	char		c;
	size_t		num;
	size_t		count;

	count = 0;
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
	count++;
	return (count);
}
