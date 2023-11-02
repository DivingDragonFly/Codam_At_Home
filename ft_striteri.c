/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:33:32 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 15:32:15 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	const size_t	total_len = ft_strlen(s);
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (i < total_len)
	{
		f(i, &s[i]);
		i++;
	}
}
