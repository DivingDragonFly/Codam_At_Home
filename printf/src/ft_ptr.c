/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:07:33 by msinke            #+#    #+#             */
/*   Updated: 2023/12/02 23:10:25 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ptr(void *value)
{
	bool	upper;

	upper = false;
	if (value == NULL)
		return (ft_string("(nil)"));
	if ((long)value == LONG_MIN)
		return (ft_string("0x8000000000000000"));
	else if ((long)value == LONG_MAX)
		return (ft_string("0x7fffffffffffffff"));
	else if ((unsigned long)value == ULONG_MAX)
		return (ft_string("0xffffffffffffffff"));
	else if ((unsigned long)value == -ULONG_MAX)
		return (ft_string("0x1"));
	else if ((long long int)value == INT_MIN)
		return (ft_string("0x1"));
	else if ((long long int)value == INT_MAX)
		return (ft_string("0x7FFFFFFF"));
	else
	{
		ft_string("0x");
		return ((print_hex((long long)value, upper)) + 2);
	}
}
