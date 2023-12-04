/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:14:14 by msinke            #+#    #+#             */
/*   Updated: 2023/12/04 15:47:36 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_string(const char *buf)
{
	int		count;

	count = 0;
	if (!buf)
		return ((int)write(1, "(null)", 6));
	while (buf[count])
	{
		ft_char(buf[count]);
		count++;
	}
	return (count);
}
