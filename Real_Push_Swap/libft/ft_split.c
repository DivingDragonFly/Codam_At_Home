/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:45:14 by msinke            #+#    #+#             */
/*   Updated: 2023/11/06 19:10:35 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **array, size_t count)
{
	while (count != SIZE_MAX)
		free(array[count--]);
	if (array)
		free(array);
}

static char	**ft_fill_array(char const *str, char div,
				char **array, size_t wordcount)
{
	size_t	end;
	size_t	begin;
	size_t	count;

	count = 0;
	end = 0;
	while (str[end] && count <= wordcount)
	{
		while (str[end] == div)
			end++;
		begin = end;
		while (str[end] != div && str[end])
			end++;
		if (begin == end)
			continue ;
		array[count] = (char *)ft_calloc(end - begin + 1, sizeof(char));
		if (!array[count])
		{
			ft_free(array, --count);
			return (NULL);
		}
		ft_memmove(array[count++], str + begin, (end - begin));
	}
	array[wordcount] = NULL;
	return (array);
}

static size_t	ft_wordcount(const char *str, char div)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i])
	{
		if ((str[i] != div && str[i - 1] == div) || (str[i] != div && i == 0))
			wordcount++;
		++i;
	}
	return (wordcount);
}

char	**ft_split(char const *original_str, char div)
{
	size_t	wordcount;
	char	**array;

	if (!original_str)
		return (NULL);
	wordcount = ft_wordcount(original_str, div);
	array = (char **)ft_calloc(wordcount + 1, sizeof(char *));
	if (!array)
		return (NULL);
	ft_fill_array(original_str, div, array, wordcount);
	return (array);
}
