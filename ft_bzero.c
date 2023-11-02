/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:16:44 by msinke            #+#    #+#             */
/*   Updated: 2023/10/29 16:31:30 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, '\0', n);
}

// int	main(void)
// {
// 	char	str[] = "blablalba";

// 	ft_bzero(str, 5);
// 	printf("%s\n", str+4);

// }