/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:59:52 by msinke            #+#    #+#             */
/*   Updated: 2023/12/02 23:10:25 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	recursive_putnbr(int n)
{
	int			count;
	long long	num;
	char		c;

	count = 0;
	num = n;
	if (num >= 10)
	{
		count += ft_putnbr((num / 10));
	}
	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr(int n)
{
	int			count;
	long long	num;

	num = n;
	count = 0;
	if (num == INT_MIN)
		return (ft_string("-2147483648"));
	else if (num == INT_MAX)
		return (ft_string("2147483647"));
	else if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		count++;
	}
	count += recursive_putnbr(num);
	return (count);
}
