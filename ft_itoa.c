/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:02:31 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 18:14:30 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(char *str, int str_len, int n, bool neg)
{
	int			i;
	long long	num;

	i = 0;
	num = n;
	str[str_len--] = '\0';
	while (num != 0)
	{
		str[str_len--] = (n % 10) + '0';
		num /= 10;
	}
	if (neg)
		str[str_len] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	long long		num;
	int				str_len;
	bool			neg;

	str_len = 0;
	num = n;
	neg = false;
	if (n < 0)
	{
		neg = true;
		++str_len;
	}
	while (num >= 10)
	{
		++str_len;
		num /= 10;
	}
	++str_len;
	str = (char *)ft_calloc(str_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = ft_fill(str, str_len, n, neg);
	return (str);
}
