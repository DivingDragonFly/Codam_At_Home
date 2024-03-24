/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:46:25 by msinke            #+#    #+#             */
/*   Updated: 2024/03/24 18:15:56 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	total_size;
	void	*ptr;

	if (num_elements == 0 || element_size == 0)
	{
		num_elements = 1;
		element_size = 1;
	}
	if (element_size > (SIZE_MAX / num_elements))
		return (NULL);
	total_size = num_elements * element_size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', total_size);
	return (ptr);
}

char	*eof(char *buffer)
{
	char	*result;

	result = NULL;
	if (!buffer || *buffer == '\0')
		return (NULL);
	result = ft_calloc(ft_strlen(buffer) + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memmove(result, buffer, ft_strlen(buffer));
	return (result);
}

char	*extract_line(char *buffer)
{
	char		*nl_position;
	size_t		line_length;
	size_t		remaining;
	char		*result;

	result = NULL;
	nl_position = ft_strchr(buffer, '\n');
	if (nl_position)
	{
		line_length = nl_position - buffer + 1;
		result = ft_calloc(line_length + 1, sizeof(char));
		if (!result)
			return (NULL);
		ft_memmove(result, buffer, line_length);
		result[line_length] = '\0';
		remaining = ft_strlen(buffer) - line_length;
		ft_memmove(buffer, nl_position + 1, remaining + 1);
		buffer[remaining] = '\0';
		return (result);
	}
	return (NULL);
}

char	*read_fd(int fd, char *buffer)
{
	char		*read_buffer;
	ssize_t		bytes_read;

	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
	{
		free (buffer);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			free (buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
	}
	free (read_buffer);
	read_buffer = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;
	char		*nl_position;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	nl_position = ft_strchr(buffer, '\n');
	if (nl_position)
	{
		result = extract_line(buffer);
		if (!result)
		{
			free(buffer);
			buffer = NULL;
		}
		return (result);
	}
	result = eof(buffer);
	free(buffer);
	buffer = NULL;
	return (result);
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char	*line;

// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (0);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	if (close(fd) == -1)
// 	{
// 		printf("Error closing file");
// 		return (0);
// 	}

// 	return (0);
// }