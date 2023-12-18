/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:39:58 by msinke            #+#    #+#             */
/*   Updated: 2023/12/18 16:44:01 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//check in chunk of buffer size

//if it hasn't reached new line, it stores in temp
// stringjoin if there are multiple temps

// if you do have /n, stringjoin in temp, and then store in result

//print and free both result and temp

// start again where left of

/*
Luca
If you read 1000 bytes and theres a newline, the read function can't backtrace
so u need to store it, and if theres multiple new line characters then its extra steps
like you should keep on reading until its eof or a new line character is found
the nreturn the buffer containing everything from AFTER the newline character
till the newline character after INCLUSIVE, store everything extra
for the next time around and go through the same process, and only read if it
is necessary
*/

char	*final_line(t_struct content)
{
	content.result = ft_calloc(content.index + 1, sizeof(char));
	if (content.result == NULL)
		return (NULL);
	ft_memcpy(content.result, content.buffer, content.index);
	ft_strlen(content.buffer);
}


char	*storage_loop(int fd, t_struct content)
{
	content.index = 0;
	read(fd, content.buffer, content.buffer_size);
	while (content.buffer[content.index])
	{
		if (content.buffer[content.index] == '\n')
		{
			return (final_line(content));
		}
	}
	return (0);
}


char	*get_next_line(int fd)
{
	static t_struct	content;

	content.buffer_size = 16;
	content.buffer = ft_calloc(content.buffer_size + 1, sizeof(char));
	content.result = NULL;
	content.temp = NULL;
	content.index = 0;
	read(fd, content.buffer, content.buffer_size);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			result = ft_calloc(i + 1, sizeof(char));
			if (result == NULL)
				return (NULL);
			ft_memcpy(result, buffer, i);
			break ;
		}
		else if (i == buffer_size - 1)
		{
			temp = ft_calloc(i + 1, sizeof(char));
			if (temp == NULL)
				return (NULL);
			ft_memcpy(temp, buffer, i);
			break ;
		}
		++i;
	}
	printf("result: %s\n", result);
	printf("temp: %s\n", temp);
	return (result);

}

int	main()
{
	int		fd;

	fd = open("random.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("Errorn\n");
		return (1);
	}
	get_next_line(fd);
	return (0);
}
