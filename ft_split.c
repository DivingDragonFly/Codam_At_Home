/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:29:18 by msinke            #+#    #+#             */
/*   Updated: 2023/11/02 20:39:22 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdint.h>

static char	**malloc_column(char const *s, char c, size_t row_count)
{
	char	**arr;
	size_t	i;
	size_t	begin;
	size_t	count;

	i = 0;
	begin = 0;
	count = 0;
	arr = (char **)ft_calloc(row_count + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i] && count <= row_count)
	{
		while (s[i] == c)
			i++;
		begin = i;
		while (s[i] != c && s[i])
			i++;
		arr[count] = (char *)ft_calloc(i - begin + 1, sizeof(char));
		if (!arr[count])
			ft_free(arr, count);
		ft_memmove(arr[count], s + begin, i - begin);
		count++;
	}
	return (arr);
}

static void	ft_free(char **arr, size_t count)
{
	while (count != SIZE_MAX)
	{
		free(arr[count]);
		count--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	row_count;

	if (!s)
		return (0);
	row_count = 0;
	i = SIZE_MAX;
	while (s[++i])
		if ((s[i] != c && s[i - 1] == c) || (s[i] != c && i == 0))
			row_count++;
	arr = (char **)malloc_column(s, c, row_count);
	if (!arr)
		return (NULL);
	return (arr);
}

int	main(void)
{
	char	**poep;
	int		i;
	int		row_count;

	row_count = 3;
	i = 0;
	poep = ft_split("         dh ", ' ');
	while (row_count > 0)
	{
		printf("%s\n", poep[i]);
		row_count--;
		i++;
	}
	return (0);
}