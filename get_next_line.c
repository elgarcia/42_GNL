/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:33:17 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/14 04:09:55 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*aux;
	size_t	i;

	i = 0;
	aux = (void *)malloc(count * size);
	if (!aux)
		return (NULL);
	else
	{
		while ((i < count))
			((char *)aux)[i++] = '\0';
	}
	return (aux);
}

static int	read_buff(int *b_read, int fd, char **buff, char **line)
{
	free_null(buff);
	*buff = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!(*buff))
	{
		free_null(line);
		return (B_READED_FAIL);
	}
	*b_read = read(fd, *buff, BUFFER_SIZE);
	if (*b_read == B_READED_FAIL || *b_read == B_READED_NULL)
	{
		free_null(buff);
		if (*b_read == B_READED_FAIL)
		{
			free_null(line);
			return (B_READED_FAIL);
		}
		else if (*b_read == B_READED_NULL)
			return (B_READED_NULL);
	}
	return (1);
}

static char	*first_read(int *b_read, int fd, char **buff, int *index)
{
	*index = 0;
	if (!(*buff) || *buff[0] == '\0')
	{
		if (*buff && *buff[0] == '\0')
			free_null(buff);
		*buff = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buff)
			return (NULL);
		*b_read = read(fd, *buff, BUFFER_SIZE);
		if (*b_read == B_READED_FAIL || *b_read == B_READED_NULL)
			return (free_null(buff));
	}
	return (*buff);
}

static char	*get_line(char **line, char **buff, int *check)
{
	size_t	i;

	*check = 0;
	i = 0;
	while (*buff && i < ft_strlen(*buff))
	{
		if (*(*buff + i) == '\n')
		{
			*line = ft_strjoin(line, *buff, i + 1);
			if (!(*line))
				return (free_null(buff));
			ft_memcpy(*buff, *buff + (i + 1), BUFFER_SIZE - i);
			*check = 1;
			return (*line);
		}
		i++;
	}
	*line = ft_strjoin(line, *buff, i);
	if (!(*line))
		return (free_null(buff));
	return (*line);
}

char	*get_next_line(int fd)
{
	int				b_read;
	static char		*buff;
	char			*line;
	int				i;
	int				aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!first_read(&b_read, fd, &buff, &i))
		return (NULL);
	while (b_read != B_READED_NULL || buff)
	{
		if (get_line(&line, &buff, &aux) == NULL)
			return (NULL);
		else if (aux == 1)
			return (line);
		i = 0;
		read_buff(&b_read, fd, &buff, &line);
		if (b_read == B_READED_FAIL)
			return (NULL);
		if (b_read == B_READED_NULL)
			return (line);
	}
	return (NULL);
}

/* #include <fcntl.h>
int	main()
{
	int	fd;
	char	*line;
	fd = open("test.txt", O_RDONLY);
	if (fd == B_READED_FAIL)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		printf("Linea obtenida: %s\n", (unsigned char *)line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);

	return (0);
} */