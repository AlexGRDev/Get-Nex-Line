/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:03:53 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/20 16:50:30 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_read_append(int fd, char *buf, char **bytes, size_t *cap)
{
	ssize_t	nread;

	nread = read(fd, buf, BUFFER_SIZE);
	if (nread <= 0)
		return ((int)nread);
	*(buf + nread) = '\0';
	*bytes = ft_bytes_join(*bytes, buf, cap);
	if (!*bytes)
		return (-1);
	return (1);
}

static char	*read_to_bytes(int fd, char *bytes)
{
	char		*buf;
	int			status;
	size_t		cap;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(bytes), NULL);
	cap = ft_strlen_gnl(bytes) + 1;
	status = 1;
	while (!ft_strchr_gnl(bytes, '\n') && status > 0)
		status = gnl_read_append(fd, buf, &bytes, &cap);
	if (status < 0)
	{
		free(buf);
		free(bytes);
		return (NULL);
	}
	free(buf);
	return (bytes);
}

static char	*extract_line(char *bytes)
{
	char	*line;
	char	*src;
	char	*dst;
	size_t	len;

	if (!bytes || !*bytes)
		return (NULL);
	src = bytes;
	len = 0;
	while (*src && *src != '\n')
	{
		src++;
		len++;
	}
	if (*src == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	dst = line;
	src = bytes;
	while (len--)
		*dst++ = *src++;
	*dst = '\0';
	return (line);
}

static char	*clean_bytes(char *bytes)
{
	char	*nl;
	char	*dst;
	char	*src;

	if (!bytes)
		return (NULL);
	nl = ft_strchr_gnl(bytes, '\n');
	if (!nl)
	{
		free(bytes);
		return (NULL);
	}
	dst = bytes;
	src = nl + 1;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*bytes = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read_to_bytes(fd, bytes);
	if (!bytes)
		return (NULL);
	if (!bytes[0])
	{
		free(bytes);
		bytes = NULL;
		return (NULL);
	}
	line = extract_line(bytes);
	if (!line)
	{
		free(bytes);
		bytes = NULL;
		return (NULL);
	}
	bytes = clean_bytes(bytes);
	return (line);
}
